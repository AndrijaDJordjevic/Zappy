##
# EPITECH PROJECT, 2023
# parser
# File description:
# arg
##

import macro
from sys import argv, exit
from macro import EXIT_SUCCESS, ARGC


class argument_parser:
    def __init__(self):
        self.port = None
        self.team_name = None
        self.machine = "localhost"

    def get_given_argument(self, args: list[str], flag: str, arg_name: str) -> str:
        for i in range(len(args)):
            if args[i] == flag:
                try:
                    return args[i + 1]
                except IndexError:
                    raise Exception(
                        f"Invalid {arg_name}. Use './zappy_ai --help' for usage information.")
        raise Exception(
            f"Invalid {arg_name}. Use './zappy_ai --help' for usage information.")

    def check_port(self, port: str) -> int:
        try:
            port = int(port)
            if port < 0 or port > 65535:
                raise Exception(
                    "Invalid port. Use './zappy_ai --help' for usage information.")
        except ValueError:
            raise Exception(
                "Invalid port. Use './zappy_ai --help' for usage information.")
        return port

    def get_arguments(self, args: list[str], argc: int) -> None:
        try:
            self.port = self.check_port(
                self.get_given_argument(args, "-p", "port"))
            self.team_name = self.get_given_argument(args, "-n", "team name")
            if argc == 7:
                self.machine = self.get_given_argument(args, "-h", "machine")
        except Exception as e:
            raise e

    def parse_arguments(self) -> None:
        if ARGC == 2 and (argv[1] == "--help" or argv[1] == "-h"):
            self.print_usage()
            exit(EXIT_SUCCESS)
        elif ARGC != 5 and ARGC != 7:
            raise Exception(
                "Not enough arguments. Use './zappy_ai --help' for usage information.")
        else:
            try:
                self.get_arguments(argv[1:], ARGC)
            except Exception as e:
                raise e

    def print_usage(self):
        print("USAGE: ./zappy_ai -p port -n name -h machine")
        print("\tport\tis the port number")
        print("\tname\tis the name of the team")
        print("\tmachine\tis the name of the machine; localhost by default")
