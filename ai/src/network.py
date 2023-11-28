##
# EPITECH PROJECT, 2023
# network
# File description:
# network
##

from macro import BUFFER, EXIT_SUCCESS
from ai.src.client import Client
import select
from sys import stderr
import re


class client_ai:
    def __init__(self, port: int, team_name: str, machine: str):
        self.port = port
        self.team_name = team_name
        self.machine = machine
        self.client_num = 0
        self.PosX = 0
        self.PosY = 0
        self.client = Client(team_name)

    def connect_client(self):
        try:
            self.client.command.socket.connect((self.machine, self.port))
            print(f"Connected to port {self.port}")
        except ConnectionRefusedError:
            raise Exception(f"Connection to port {self.port} was refused.")
        except Exception as e:
            raise Exception(
                f"An error occurred while connecting to the port: {e}")

    def receive_and_store(self):
        welcome = self.client.command.receive_message(timer=5)
        print(welcome)
        self.client.command.send_message(self.team_name)
        print(self.team_name)
        data = self.client.command.receive_message(timer=5)

        if data is None:
            print("Error while receiving data from the server.", file=stderr)
            exit(84)

        pattern = re.compile(r'^[0-9]+\n[0-9]+ [0-9]+\n$')
        match = pattern.match(data)
        if match is None:
            print("Error while receiving data from the server.", file=stderr)
            exit(84)
        print(data)

        lines = data.split('\n')
        self.client_num = int(lines[0])
        pos_values = lines[1].split(' ')
        self.PosX = int(pos_values[0])
        self.PosY = int(pos_values[1])
        print(self.client_num, end="\n")
        print(self.PosX, end=" ")
        print(self.PosY, end="\n")

    def start_communication(self):
        try:
            with self.client.command.socket as sock:
                self.receive_and_store()
                while True:
                    ready_to_read, _, _ = select.select([sock], [], [], 0)
                    if ready_to_read:
                        data = self.client.command.receive_message()
                        if data == "dead":
                            break
                    self.client.handle_ai()

        except Exception as e:
            raise e
        except KeyboardInterrupt:
            print("\nAI shutdown.", end="\n")
            exit(EXIT_SUCCESS)
