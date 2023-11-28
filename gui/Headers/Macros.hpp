/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** macros
*/

#ifndef MACROS_HPP_
    #define MACROS_HPP_

    #include <iostream>

    #define EXIT_ERROR 84

    #define IS_ARG_HELP (argc == 2 && (std::string(argv[1]) == "-help" || std::string(argv[1]) == "-h"))
    #define INVALID_NUMBER_OF_ARGUMENTS (ac != 3 && ac != 5)
    #define ARGUMENTS_ERROR "Invalid number of arguments. Try './zappy_gui -help'."

#endif /* !MACROS_HPP_ */
