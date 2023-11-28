##
# EPITECH PROJECT, 2023
# B-YEP-400-PAR-4-1-zappy-martin.petit
# File description:
# levelAlgo
##

from commands import Commands
from macro import FULL, STARVING
from classNeural import NeuralNetwork, foodPercentage
from sys import stderr
from Actions import Actions
from elevation_mandatory import elevation_mandatory
from tile_way_constants import TILE_WAY_LOOK_RESPONSE, TILE_WAY_BROADCAST_RESPONSE
import random

class Client:
    def __init__(self, team_name_in: str):
        self.current_look = None
        self.command = Commands()
        self.count_fork = 0
        self.direction = -1
        self.objects_to_incant = False
        self.ready_to_incant = False
        self.joining_incantation = False
        self.doing_incantation = False
        self.team_name = team_name_in
        self.action = Actions.SEARCHING_FOOD
        self.direction_random = 0
        self.steps_in_current_direction = 0
        self.steps_to_take_in_current_direction = self.get_random_steps()
        self.plan = []
        self.count_set = 0

    def go_to_tile(self, move_to_tile): # DONE
        if move_to_tile == []:
            return
        print(f"Move to food: {move_to_tile}\n")
        for move in move_to_tile:
            self.command.send_command(move)
            ret = self.get_response_now()
            if ret != "ok\n":
                print(f"Error: Forward, excpected 'ok' got: {ret}\n")
                exit(84)

    def searching_food(self): # DONE
        food_pos = [i for i, tile in enumerate(self.current_look) if tile['food'] > 0]

        closest_food_position = food_pos[0] if food_pos else None

        if closest_food_position is None or closest_food_position > 8:
            self.command.send_command("Forward")
            ret = self.get_response_now()

            if ret != "ok\n":
                print(f"Error: Right, excpected 'ok' got: {ret}\n")
                exit(84)
            self.current_look = self.look_around()
            self.searching_food()
            return

        move_to_food = TILE_WAY_LOOK_RESPONSE[closest_food_position]
        self.go_to_tile(move_to_food)

        while self.command.player.food < 150:
            self.command.send_command("Take", parameter="food")

            if self.get_response_now() == "ok\n":
                self.command.player.food += 1
            else:
                self.current_look = self.look_around()
                self.searching_food()
                return
        self.action = Actions.NOTHING

    def find_ressources_pos(self, ressource: str): # DONE
        ressource_pos = [i for i, tile in enumerate(self.current_look) if tile[ressource] > 0]

        closest_ressource_pos = ressource_pos[0] if ressource_pos else None

        if closest_ressource_pos is None or closest_ressource_pos > 8:
            print(f"No {ressource} on the map, i'll check around")
            self.command.send_command("Right")
            ret = self.get_response_now()
            if ret is None:
                print(f"Error: Right, excpected 'ok' got: {ret}\n")
                exit(84)
            if ret != "ok\n":
                print(f"Error: Forward, excpected 'ok' got: {ret}\n")
                exit(84)
            self.current_look = self.look_around()
            self.find_ressources_pos(ressource)
            return
        return closest_ressource_pos

    def searching_objects(self): # DONE
        ev = elevation_mandatory(self.command.player.level)
        required_ressources = ev.get_inventory_requirements()

        if ev.hasErrorRaised is True:
            print("Error: Invalid level")
            exit(84)

        for ressource, quantity in required_ressources.items():
            if quantity == 0 or self.command.player.inventory[ressource] >= quantity:
                continue
            ressource_pos = self.find_ressources_pos(ressource)
            move_to_ressource = TILE_WAY_LOOK_RESPONSE[ressource_pos]
            self.go_to_tile(move_to_ressource)
            while self.command.player.inventory[ressource] < quantity:
                self.command.send_command("Take", parameter=ressource)
                if self.get_response_now() == "ok\n":
                    self.command.player.inventory[ressource] += 1
                else:
                    self.current_look = self.look_around()
                    ressource_pos = self.find_ressources_pos(ressource)
                    move_to_ressource = TILE_WAY_LOOK_RESPONSE[ressource_pos]
                    self.go_to_tile(move_to_ressource)

            if self.command.player.food < 85:
                self.searching_food()

        for ressource, quantity in required_ressources.items():
            if self.command.player.inventory[ressource] >= quantity:
                continue
            else:
                self.action = Actions.SEARCHING_OBJECTS
                self.searching_objects()
                return
        self.objects_to_incant = True
        self.action = Actions.READY_TO_INCANT


    def get_random_steps(self):
        return random.randint(1, 10)
    
    def change_direction(self):
        self.direction_random = random.choice([0, 1, 2, 3])
        self.steps_in_current_direction = 0
        self.steps_to_take_in_current_direction = self.get_random_steps()
    
    def plan_move(self):
        if self.direction_random == 0:
            print("Going forward")
            self.plan.append("forward")
        elif self.direction_random == 1:
            print("Going Right")
            self.plan.append("right")
            self.plan.append("forward")
        elif self.direction_random == 2:
            print("Going Right")
            self.plan.append("right")
            self.plan.append("right")
            self.plan.append("forward")
        elif self.direction_random == 3:
            print("Going Left")
            self.plan.append("left")
            self.plan.append("forward")

    def move_random(self):
        if not self.plan:
            if self.steps_in_current_direction == self.steps_to_take_in_current_direction:
                self.change_direction()
            self.plan_move()
        self.command.send_command(self.plan.pop(0))
        self.steps_in_current_direction += 1
    
    def random_movement(self):
        action = random.randint(0,2)

        if action == 0: 
            self.command.send_command("Forward")
        elif action == 1:
            self.command.send_command("Right")
        elif action == 2:
            self.command.send_command("Left")

        response = self.get_response_now()
        if response == "ok\n":
            print("Command executed successfully")
        else:
            print(f"Error: Command didn't get a valid response: {response}")
    
    def drop_items_for_incantation(self):
        ev = elevation_mandatory(self.command.player.level)
        required_items = ev.get_inventory_requirements()

        for item, quantity in required_items.items():
            for _ in range(quantity):
                command = f'Set {item}'
                self.command.send_command(command)

                response = self.get_response_now()
                if response == "ok\n":
                    print(f'{item} dropped successfully')
                else:
                    print(f'Error dropping {item}. Server response: {response}')

    def get_items_to_drop(self):
        ev = elevation_mandatory(self.command.player.level)
        required_items = ev.get_inventory_requirements()
        print("Required_items: ", required_items)
        items_to_drop = []

        for item, quantity in required_items.items():
            items_to_drop.extend([item] * quantity)

        return items_to_drop

    def drop_next_item(self):
        if  self.command.player.level > 1:
            current_level = self.command.player.level
            elevation_req = elevation_mandatory(current_level)
            req_items = elevation_req.get_inventory_requirements()
            inventory = self.command.player.inventory

            items_to_drop = [item for item, count in req_items.items() if count > 0 and inventory.get(item, 0) >= count]

            if not items_to_drop:
                return 1

            item_to_drop = items_to_drop[0]

            command = f'Set {item_to_drop}'
            self.command.send_command(command)

            response = self.get_response_now()
            if response == "ok\n":
                print(f'{item_to_drop} dropped successfully')
                self.command.process_server_inventory()
                return 0
            else:
                print(f'Error dropping {item_to_drop}. Server response: {response}')
                return 0


    def start_incantation(self): #TO CHECK
        current_level = self.command.player.level
        look_incantation = self.look_around()

        if not self.objects_to_incant:
            print(f'Incantation not possible for level {current_level}. Requirements not met.')
            return

        player_pos = [i for i, tile in enumerate(look_incantation) if tile['player'] > 0]
        closest_player_position = player_pos[0] if player_pos else None

        print("Closest Player: ",closest_player_position)
        print("lvl: ", self.command.player.level)
        print("Fork count :", self.count_fork)
        if self.count_fork == 10:
            rand = random.randint(1, 2)
            if (rand == 1):
                self.command.send_command("Forward")
                response = self.get_response_now()
                if response == "ok\n":
                    print("Successful Forward")
                    self.count_fork += 1
                    return
                else:
                    print("Error during Forward")
                    return
            elif rand == 2:
                self.command.send_command("Right")
                response = self.get_response_now()
                if response == "ok\n":
                    print("Successful Right")
                    self.count_fork += 1
                    return
                else:
                    print("Error during Right")
                    return
        
        if self.count_fork == 11:
            self.command.send_command("Fork")
            response = self.get_response_now()
            if response == "ok\n":
                print("Successful Forking")
                self.count_fork = 0
                return
            else:
                print("Error during Forking")
                return
        
        if closest_player_position != 0 and self.command.player.level > 1:
            print("No player on the map")
            print("Random directions")
            self.random_movement()
            return
        
        if self.command.player.level > 1 and self.drop_next_item() == 0:
            return
        print("Can incantate")
        self.command.send_command("Incantation")
        self.action = Actions.UNDERGOING_INCANTATION
        response = self.get_response_now()
        print("Response : ", response)
        if response == f"Elevation underway. Current level: {self.command.player.level + 1}\n":
            print("Player levelled up!")
            self.action = Actions.NOTHING
            self.command.player.level += 1
            return
        else:
            print(f"Error: Incantation didn't get a valid response: {response}")
            self.action = Actions.NOTHING
            self.count_fork += 1
            return

    def get_response_now(self) -> str | None: # DONE
        response = None
        while response is None or response == "":
            response = self.command.receive_message(timer=0)
        if response == "dead":
            exit(0)
        if response.startswith("message"):
            if self.command.parse_broadcast(response) != 0:
                print("Error: Broadcast parser")
                exit(84)
            return self.get_response_now()
        self.command.command_queue.pop(0)
        return response

    def get_broadcast_response(self) -> str | None: # DONE
        reponse = None
        response = self.command.receive_message(timer=7)

        if response.startswith("message"):
            if self.command.parse_broadcast(response) != 0:
                print("Error: Broadcast parser")
                exit(84)
            self.command.command_queue.pop(0)
            return response
        else:
            return None

    def direction_handling(self, directions: list[str]) -> int: # TO CHECK
        if direction == "STOP":
            return 0
        for direction in directions:
            self.command.send_command(direction)
            ret = self.get_response_now()
            if ret == "dead":
                exit(0)
            elif ret == "ok\n":
                continue
            else:
                print("Error: Direction handling", file=stderr)
                exit(84)

    def join_emitter(self): # SHOULD BE A LOOP
        if self.joining_incantation is False:
            return
        self.get_response_now()
        if self.command.broadcast_waiting is False:
            pass
            # self.command.send_command("Broadcast", parameter=f"{self.command.player.}")
            # self.get_response_now()
        direction_handling = {
            0: self.command.direction_handling(["STOP"]),
            1: self.command.direction_handling(["Forward"]),
            2: self.command.direction_handling(["Forward", "Left", "Forward", "Right"]),
            3: self.command.direction_handling(["Left", "Forward"]),
            4: self.command.direction_handling(["Left", "Forward", "Left", "Forward"]),
            5: self.command.direction_handling(["Left", "Left", "Forward"]),
            6: self.command.direction_handling(["Right", "Forward", "Right", "Forward"]),
            7: self.command.direction_handling(["Right", "Forward"]),
            8: self.command.direction_handling(["Forward", "Right", "Forward", "Left"]),
        }
        if self.command.player.food >= 150 and self.direction in range(-1, 9):
            try:
                if direction_handling[self.direction] == 0:
                    self.direction = -1
                    self.command.send_command(
                        "Broadcast", parameter=f"\"{self.team_name} {self.command.player.level} JOIN\"")
                    return
            except KeyError:
                self.direction = -1
                return

    def broadcast(self, team_name: str, level: int, status: str): # TO CHECK
        self.command.send_command("Broadcast", parameter=f"\"{team_name} {level} {status}\"\n")

    def check_broadcast(self): # TO CHECK
        if self.command.broadcast_level != self.command.player.level: # should respond to the broadcast
            self.command.clear_broadcast()
            return False
        if self.doing_incantation is False and self.command.broadcast_status == "WAITING":
            if self.command.broadcast_status == "WAITING":
                self.broadcast(self.team_name, self.command.player.level, "JOIN")
                self.joining_incantation = True
                return True

    def can_call_incantation(self, level: int) -> bool: # TO CHECK
        if self.command.broadcast_waiting is False or self.command.broadcast_level != level \
            or self.team_name != self.command.broadcast_team:
            self.command.clear_broadcast()
            return True
        if self.command.broadcast_status == "WAITING":
            self.joining_incantation = True
            return False
        if self.command.broadcast_status == "JOIN":
            return False
        if self.command.broadcast_status == "START" or self.command.broadcast_status == "END" \
            or self.command.broadcast_status == "CANCEL":
            return True

    def try_incantation(self): # DOING
        ev = elevation_mandatory(self.command.player.level)
        nb_players = ev.get_nb_player(self.command.player.level)

        if self.objects_to_incant is False:
            self.action = Actions.SEARCHING_OBJECTS
            return self.action
        if nb_players == 1:
            self.start_incantation()
            return Actions.UNDERGOING_INCANTATION

        if self.can_call_incantation(self.command.player.level) is True:
            self.action = Actions.WAITING_INCANTATION
            return self.action
        else:
            self.action = Actions.JOINING_INCANTATION
            return self.action

    def are_team_mates_ready(self) -> bool: # TO CHECK
        if self.team_name != self.command.broadcast_team:
            return False
        if self.command.player.level != self.command.broadcast_level:
            return False
        if self.command.broadcast_status != "JOIN":
            return False
        if self.command.broadcast_direction != 0:
            return False
        return True

    def check_for_joiners(self, nb_players: int) -> int | None: # TO CHECK
        valid_players = 1

        while True:
            self.broadcast(self.team_name, self.command.player.level, "WAITING")
            broadcast = self.get_broadcast_response()

            if broadcast is None:
                break

            if self.are_team_mates_ready() is True:
                self.command.clear_broadcast()
                valid_players += 1
            if valid_players == nb_players:
                print("All players are ready to start incantation")
                return 0

        return None

    def start_waiting_allowed(self, nb_players: int) -> bool: # TO CHECK
        self.broadcast(self.team_name, self.command.player.level, "WAITING")
        player_joining = 1

        while True:
            broadcast = self.get_broadcast_response()

            if broadcast is None:
                break

            if self.command.broadcast_team != self.team_name:
                continue
            if self.command.broadcast_level != self.command.player.level:
                continue
            if self.command.broadcast_status == "WAITING":
                self.action = Actions.JOINING_INCANTATION
                return False
            if self.command.broadcast_status == "JOIN":
                player_joining += 1
            self.command.clear_broadcast()

        return player_joining >= nb_players

    def wait_for_incantation(self):
        ev = elevation_mandatory(self.command.player.level)
        nb_players = ev.get_nb_player(self.command.player.level)

        if self.start_waiting_allowed(nb_players) is False:
            self.broadcast(self.team_name, self.command.player.level, "JOIN")
            print("Not enough players to start incantation")
            return -1

        while True:
            self.current_look = self.look_around()
            if self.current_look is None or self.current_look == "" or self.current_look == "dead":
                print("look: ", self.current_look)
                print("exit; No more players are ready to start incantation")
                exit(84)
            player = self.current_look[0]['player']
            if player == 0:
                self.command.send_command("Take", parameter="food")
                if self.get_response_now() != "ok\n":
                    print("No food on the tile")
            if self.command.broadcast_waiting is True:
                status = self.check_for_joiners(nb_players)
                if status is None:
                    print("No more players are ready to start incantation yet")
                    continue
                else:
                    break
            else:
                print("No broadcast received")
                self.command.send_command("Take", parameter="food")
                ret = self.get_response_now()
                if ret != "ok\n":
                    print("No food on the tile\n")
        print("All players are ready to start incantation")
        return 0

    def handle_incantations_options(self): # DONE
        print("handle_incantations_options\n")
        print("Actions = ", self.action)
        match self.action:
            case Actions.SEARCHING_FOOD:
                print("SEARCHING_FOOD\n")
                self.command.clear_broadcast()
                return
            case Actions.NOTHING:
                pass
            case Actions.READY_TO_INCANT:
                print("READY_TO_INCANT\n")
                self.start_incantation()

    def look_around(self) -> list[list[dict[str, int]]] | None: # DONE
        self.command.send_command("Look")
        look_content = self.get_response_now()
        print("Look content", look_content)

        if look_content is None or look_content == "dead\n":
            print(f"Error: Look around, excpected look ret but got: {look_content}", file=stderr)
            exit(0 if look_content == "dead\n" else 84)
        look_content = self.command.format_look_response(look_content)
        return look_content

    def check_food_needs(self) -> int: # DONE
        if self.current_look is None:
            return -1
        food_map = sum(tile['food'] for tile in self.current_look)
        food_per = round(foodPercentage(len(self.current_look), food_map))
        neural_network = NeuralNetwork([self.command.player.food, food_per])
        is_food_enough = neural_network.run_neural_network()

        if is_food_enough == FULL:
            print("Food is enough\n")
            if self.action == Actions.SEARCHING_FOOD or self.action == Actions.NOTHING:
                # if we are searching food or doing nothing otherwise it means we are going for an incantation/doing an incantation and we don't need to search for food
                self.action = Actions.SEARCHING_OBJECTS
        else:
            print("Food is not enough\n")
            self.action = Actions.SEARCHING_FOOD

    def handle_actions(self):
        if self.current_look is None:
            return
        if self.action == Actions.NOTHING:
            if self.command.player.food < 150:
                self.action = Actions.SEARCHING_FOOD
            elif self.objects_to_incant is False:
                self.action = Actions.SEARCHING_OBJECTS
        if self.action != Actions.SEARCHING_FOOD and self.action != Actions.JOINING_INCANTATION \
        and self.objects_to_incant is False:
            self.action = Actions.SEARCHING_OBJECTS

        match self.action:
            case Actions.SEARCHING_FOOD | Actions.NOTHING:
                print("I need food, i'm starting to look !\n")
                self.searching_food()
                self.handle_actions()
                return
            case Actions.SEARCHING_OBJECTS:
                if self.command.player.level >= 1 and self.command.player.level <= 7:
                    print("I don't need food, I need to search for objects !\n")
                    self.searching_objects()
                else:
                    print("I'm level 8, I don't need to search for objects !\n")
                    self.action = Actions.INTERCEPTING_INCANTION
                pass
            case _:
                pass
        self.handle_incantations_options()

    def handle_ai(self):
        print("Starting AI")
        print()
        self.current_look = self.look_around()
        if self.current_look is None:
            exit (84)
        self.command.print_inventory()
        self.check_food_needs()
        print("Level player: ", self.command.player.level)

        self.handle_actions()
