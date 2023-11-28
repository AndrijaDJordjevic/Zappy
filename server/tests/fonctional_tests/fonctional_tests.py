#!/usr/bin/env python3
##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

from test_server import Test_connection_serv
from test_serv_ai_auth import Test_ser_ai_auth
from test_serv_gui_auth import Test_ser_gui_auth
from test_command_msz import Test_command_msz
from test_command_tna import Test_command_tna

def fonctional_test ():
    print("##############################################################################################################################################################################################")
    print("                                                                                                                                                                                              ")
    lettres_geantes = {
        "F": ["  #####", "  #", "  ####", "  #", "  #", "  #"],
        "U": ["#   #", "#   #", "#   #", "#   #", "#   #", "#####"],
        "N": ["  #   #", "  ##  #", "  # # #", "  #  ##", "  #   #", "  #   #"],
        "C": ["   ####", "  #", "  #", "  #", "  #", "   ####"],
        "T": ["  #####", "    #", "    #", "    #", "    #", "    #"],
        "O": ["#####", "#   #", "#   #", "#   #", "#   #", "#####"],
        "I": ["   ###", "    #", "    #", "    #", "    #", "   ###"],
        "A": ["    #", "   # #", "  #   #", "  #   #", " #######", " #     #"],
        "L": ["  #", "  #", "  #", "  #", "  #", "  #####"],
        "E": ["  #####", "  #", "  #####", "  #", "  #", "  #####"],
        "S": ["  #####", " #", "  ###", "     #", "     #", " ####"],
        " ": ["", "", "", "", "", ""]
    }

    message = "FUNCTIONAL TEST"
    lignes = ["", "", "", "", "", ""]

    for lettre in message:
        lettre_geante = lettres_geantes.get(lettre.upper(), lettres_geantes[" "])
        for i in range(len(lignes)):
            ligne_actuelle = lettre_geante[i]
            espaces_supplementaires = " " * (10 - len(ligne_actuelle))
            lignes[i] += ligne_actuelle + espaces_supplementaires

    for ligne in lignes:
        print(ligne)
    print("                                                                                                                                                                                              ")
    print("##############################################################################################################################################################################################")

def main():
    fonctional_test()
    Test_connection_serv()
    Test_ser_ai_auth()
    Test_ser_gui_auth()
    Test_command_msz()
    Test_command_tna()
    print("##############################################################################################################################################################################################")

if __name__ == '__main__':
    main()