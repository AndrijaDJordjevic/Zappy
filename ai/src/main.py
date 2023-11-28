#!/usr/bin/env python3

from sys import exit, stderr, path
path.append('ai/src/')  # import all the file you want in this directory
from ai.src.network import client_ai
from ai.src.argument_parser import argument_parser
from ai.src.macro import EXIT_ERROR
from signal import signal, SIGPIPE, SIG_DFL
signal(SIGPIPE, SIG_DFL)


def main():
    arg_parser = argument_parser()

    try:
        arg_parser.parse_arguments()
        client = client_ai(
            arg_parser.port, arg_parser.team_name, arg_parser.machine)
        client.connect_client()
        client.start_communication()
        # Instantiate and use your AI agent class here, passing the retrieved arguments as needed
    except Exception as e:
        print(f"Error: {str(e)}", file=stderr)
        exit(EXIT_ERROR)


if __name__ == "__main__":
    main()
