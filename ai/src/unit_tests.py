#!/usr/bin/env python3

from argument_parser import argument_parser
import unittest

arg_parser = argument_parser()
valid_args = ["./main.py", "-p", "8080", "-n", "myTeam", "-h", "127.0.0.1"]
invalid_args = ["./main.py", "-p", "8080", "-n", "myTeam", "-h"]
invalid_args_no_port = ["./main.py", "-n"]
invalid_args_no_name = ["./main.py", "-p"]
invalid_args_no_port_no_name = ["./main.py"]

# print("USAGE: ./zappy_ai -p port -n name -h machine")


class TestArgumentParser(unittest.TestCase):
    # Test get_given_argument
    #################################################################################################################

    def test_01_get_given_argument_valid_port(self):
        self.assertEqual(arg_parser.get_given_argument(
            valid_args, "-p", "port"), "8080")

    def test_02_get_given_argument_valid_name(self):
        self.assertEqual(arg_parser.get_given_argument(
            valid_args, "-n", "name"), "myTeam")

    def test_03_get_given_argument_valid_machine(self):
        self.assertEqual(arg_parser.get_given_argument(
            valid_args, "-h", "machine"), "127.0.0.1")

    def test_04_get_given_argument_invalid_machine(self):
        self.assertRaises(Exception, arg_parser.get_given_argument,
                          invalid_args, "-h", "machine")

    def test_05_get_given_argument_missing_arguments(self):
        self.assertRaises(Exception, arg_parser.get_given_argument,
                          invalid_args_no_port, "-p", "port")
        self.assertRaises(Exception, arg_parser.get_given_argument,
                          invalid_args_no_name, "-n", "name")
        self.assertRaises(Exception, arg_parser.get_given_argument,
                          invalid_args_no_port_no_name, "-n", "name")

    # Test check_port #################################################################################################################

    def test_06_argument_parser_negative_port(self):
        self.assertRaises(Exception, arg_parser.check_port, "-1")

    def test_07_argument_parser_out_of_range_port(self):
        self.assertRaises(Exception, arg_parser.check_port, "65536")
        self.assertRaises(Exception, arg_parser.check_port, "-4567")

    def test_08_argument_parser_positive_port(self):
        self.assertEqual(arg_parser.check_port("8080"), 8080)

    # Test get_arguments #################################################################################################################
    def test_09_get_arguments_valid_args(self):
        self.assertIsNone(arg_parser.get_arguments(valid_args, 7))

    def test_10_get_arguments_invalid_args(self):
        self.assertRaises(Exception, arg_parser.get_arguments, invalid_args, 7)
        self.assertRaises(Exception, arg_parser.get_arguments,
                          invalid_args_no_port, 3)
        self.assertRaises(Exception, arg_parser.get_arguments,
                          invalid_args_no_name, 3)
        self.assertRaises(Exception, arg_parser.get_arguments,
                          invalid_args_no_port_no_name, 1)


class TestClientAI(unittest.TestCase):
    pass


if __name__ == "__main__":
    unittest.main()
