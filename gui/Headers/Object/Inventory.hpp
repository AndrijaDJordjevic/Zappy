/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Inventory
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

class Inventory {
    public:
        Inventory();
        ~Inventory();

    void setInventory(int food, int line, int dera, int sib, int mend, int phir, int thys);

    void setFood(int food);
    void setLinemate(int linemate);
    void setDeraumere(int deraumere);
    void setSibur(int sibur);
    void setMendiane(int mendiane);
    void setPhiras(int mendiane);
    void setThystame(int thystame);

    int getFood(void);
    int getLinemate(void);
    int getDeraumere(void);
    int getSibur(void);
    int getMendiane(void);
    int getPhiras(void);
    int getThystame(void);

    private:
        int food_;
        int linemate_;
        int deraumere_;
        int sibur_;
        int mendiane_;
        int phiras_;
        int thystame_;
};

#endif /* !INVENTORY_HPP_ */
