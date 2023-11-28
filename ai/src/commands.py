##
# EPITECH PROJECT, 2023
# B-YEP-400-PAR-4-1-zappy-martin.petit
# File description:
# commands
##

from macro import BUFFER
from socket import socket, AF_INET, SOCK_STREAM
from player import Player
import select
import re


class Commands:
    def __init__(self):
        self.location = [0, 0]
        self.socket = socket(AF_INET, SOCK_STREAM)
        self.player = Player()
        self.command_queue = []
        self.broadcast_direction = -1
        self.broadcast_team = ""
        self.broadcast_level = 0
        self.broadcast_status = ""
        self.broadcast_waiting = False

    def send_message(self, message: str):
        self.socket.send(message.encode())

    def clear_broadcast(self):
        self.broadcast_direction = -1
        self.broadcast_team = ""
        self.broadcast_level = 0
        self.broadcast_status = ""
        self.broadcast_waiting = False

    def parse_broadcast(self, message) -> int:
        if not message.startswith("message"):
            return -1
        message = message.replace('"', "")
        print(f"message received='{message}'")
        pattern = r'message (\d+), ([^"]+) (\d+) (WAITING|JOIN|CANCEL|START|END)\n'
        match = re.match(pattern, message)

        if match is None:
            print("Error: Invalid broadcast message received.")
            return -1
        else:
            try:
                self.broadcast_direction = int(match.group(1))
                self.broadcast_team = match.group(2)
                self.broadcast_level = int(match.group(3))
                self.broadcast_status = match.group(4)
            except ValueError:
                print("Error: ValueError broadcast message received.")
                return -1
            if self.broadcast_direction < 0 or self.broadcast_direction > 8:
                self.clear_broadcast()
                print("Error: Invalid broadcast direction received.")
                return -1
            if self.broadcast_level != self.player.level:
                self.clear_broadcast()
                return 0
            self.broadcast_waiting = True
            return 0


    def receive_message(self, timer=0) -> str:
        self.socket.setblocking(0)  # Set socket to non-blocking mode
        try:
            ready = select.select([self.socket], [], [],
                                  timer)  # Wait for 3 seconds
            if ready[0]:
                data = self.socket.recv(BUFFER).decode()
                if not data:
                    raise Exception("The server closed the connection.")
                return data
            else:
                return None  # Skip if no data available
        except UnicodeDecodeError as e:
            raise Exception(
                f"An error occurred while decoding the message sent by the server:\n{e}")

    def look_parser(self):
        self.send_message("Look")
        print("Look: ")
        message = self.receive_message(timer=3)
        print(f"message='{message}'\n")
        i = True
        if (message.startswith("message")):
            while i == True:
                message2 = self.receive_message(timer=3)
                if (self.look_response(message2) == 1):
                    i = False

        # Clean brackets from the message
        cleaned_message = message[1:-1]

        tiles = cleaned_message.split(',')

        objects = ['player', 'linemate', 'deraumere',
                   'sibur', 'mendiane', 'phiras', 'thystame', 'food']

        res = [
            {obj: tile.split().count(obj) for obj in objects}
            for tile in tiles
        ]
        print("Our Look:")
        print(res)
        print()
        return res



    def process_server_inventory(self) -> dict[str, int] | None:
        self.send_command("Inventory")
        serv_ret_val = self.get_command_response(timer=5)
        if serv_ret_val != 0:
            print("failed to get server inventory: ", serv_ret_val)
            return None
        return self.player.inventory

    def get_player_infos(self) -> Player:
        self.player.inventory = self.process_server_inventory()
        self.player.food = self.player.food
        self.player.level = self.player.level

        return self.player

    def print_inventory(self):
        print("Player Inventory:", self.player.inventory,
              "food: ", self.player.food)

    def send_command(self, command: str, parameter=None) -> None:
        if parameter:
            self.send_message(f"{command} {parameter}")
        else:
            self.send_message(command)
        self.command_queue.append(command)

    def forward_response(self, response: str) -> None:
        if response != "ok\n":
            raise Exception(f"Forward command failed: {response}")

    def left_response(self, response: str) -> None:
        if response != "ok\n":
            raise Exception(f"Left command failed: {response}")

    def right_response(self, response: str) -> None:
        if response != "ok\n":
            raise Exception(f"Right command failed: {response}")

    def format_look_response(self, response: str) -> list[dict[str, int]]:
        # Clean brackets from the message
        cleaned_message = response[1:-1]

        tiles = cleaned_message.split(',')

        objects = ['player', 'linemate', 'deraumere',
                   'sibur', 'mendiane', 'phiras', 'thystame', 'food']

        res = [
            {obj: tile.split().count(obj) for obj in objects}
            for tile in tiles
        ]
        return res

    def look_response(self, response: str) -> None:
        if response[0] == '[' and response[-1] == ']':
            return
        else:
            raise Exception(f"Look command failed: {response}")

    def inventory_response(self, response: str) -> None:
        pattern = \
            r"\[food (\d+) , linemate (\d+) , deraumere (\d+) , sibur (\d+) , mendiane (\d+) , phiras (\d+) , thystame (\d+)\]\n"
        match = re.match(pattern, response)
        if match:
            self.player.food = int(match.group(1))
            try:
                self.player.inventory['linemate'] = int(match.group(2))
                self.player.inventory['deraumere'] = int(match.group(3))
                self.player.inventory['sibur'] = int(match.group(4))
                self.player.inventory['mendiane'] = int(match.group(5))
                self.player.inventory['phiras'] = int(match.group(6))
                self.player.inventory['thystame'] = int(match.group(7))
            except KeyError:
                print("KeyError failed: \n'" + response + "'")
                raise Exception(f"Inventory command failed: {response}")
        else:
            print("Match failed: \n'" + response + "'")
            raise Exception(f"Inventory command failed: {response}")

    def broadcast_response(self, response: str) -> None:
        if response != "ok\n":
            raise Exception(f"Broadcast command failed: {response}")

    def connect_nbr_response(self, response: str) -> None:
        if not isinstance(response, int):
            raise Exception(f"Connect_nbr command failed: {response}")

    def fork_response(self, response: str) -> None:
        if response != "ok\n":
            raise Exception(f"Fork command failed: {response}")

    def eject_response(self, response: str) -> None:
        if response != "ok\n" and response != "ko":
            raise Exception(f"Eject command failed: {response}")

    def take_response(self, response: str) -> None:
        if response != "ok\n" and response != "ko":
            raise Exception(f"Eject command failed: {response}")

    def set_response(self, response: str) -> None:
        if response != "ok\n" and response != "ko":
            raise Exception(f"Eject command failed: {response}")

    def incantation_response(self, response: str) -> None:
        pattern = r"Elevation underway. Current level: (\d+)\n"
        match = re.match(pattern, response)

        if match:
            self.player.level = int(match.group(1))
        else:
            raise Exception(f"Incantation command failed: {response}")

    def no_response(self, response: None) -> None:
        return

    def execute_command_response(self, response: str) -> None:
        commands = {
            "Forward": self.forward_response,
            "Left": self.left_response,
            "Right": self.right_response,
            "Look": self.look_response,
            "Inventory": self.inventory_response,
            "Broadcast": self.broadcast_response,
            "Connect_nbr": self.connect_nbr_response,
            "Fork": self.fork_response,
            "Eject": self.eject_response,
            "Take": self.take_response,
            "Set": self.set_response,
            "Incantation": self.incantation_response,
            None: self.no_response
        }
        first_cmd = self.command_queue[0]
        try:
            commands[first_cmd](response)
            self.command_queue.pop(0)
        except KeyError:
            raise Exception(f"Unknown command '{first_cmd}'")

    def get_command_response(self, timer=0) -> int:
        ret = self.receive_message(timer=timer)

        if ret == "dead":
            print("Server is dead")
            return 1
        elif ret == None or ret == "":
            return 0
        if ret.startswith("message"):
            if self.parse_broadcast(ret) != 0:
                print(f"Broadcast failed excepted message <direction>, <teamname> <level> <status> but got: {ret}.\n")
                exit(84)
            try:
                return self.get_command_response(timer=timer)
            except Exception as e:
                return 1
        try:
            self.execute_command_response(ret)
        except Exception as e:
            return 1
        return 0
