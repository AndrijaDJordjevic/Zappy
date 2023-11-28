/*
** EPITECH PROJECT, 2023
** core.hpp
** File description:
** core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include "Broadcaster.hpp"
    #include "Network.hpp"

class Core {
    public:
        Core() = delete;
        Core(Network& server, Broadcaster& caster);
        ~Core();

        int run(void);

    private:
        Network _server;
        Broadcaster _caster;
};

#endif /* !CORE_HPP_ */
