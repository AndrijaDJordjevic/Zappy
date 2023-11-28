##
## EPITECH PROJECT, 2023
## zappy
## File description:
## elevation_mandatory
##

class elevation_mandatory:
    def __init__(self, level: int) -> None:
        self.nb_player = self.get_nb_player(level)
        self.linemate = self.get_linemate(level)
        self.deraumere = self.get_deraumere(level)
        self.sibur = self.get_sibur(level)
        self.mendiane = self.get_mendiane(level)
        self.phiras = self.get_phiras(level)
        self.thystame = self.get_thystame(level)
        self.__errorRaised = False

    def hasErrorRaised(self) -> bool:
        return self.__errorRaised

    def get_inventory_requirements(self) -> dict:
        return {
            "linemate": self.linemate,
            "deraumere": self.deraumere,
            "sibur": self.sibur,
            "mendiane": self.mendiane,
            "phiras": self.phiras,
            "thystame": self.thystame,
        }

    def get_nb_player(self, level: int) -> int:
        try:
            return [
                1,
                2,
                2,
                4,
                4,
                6,
                6,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1

    def get_linemate(self, level: int) -> int:
        try:
            return [
                1,
                1,
                2,
                1,
                1,
                1,
                2,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1

    def get_deraumere(self, level: int) -> int:
        try:
            return [
                0,
                1,
                0,
                1,
                2,
                2,
                2,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1

    def get_sibur(self, level: int) -> int:
        try:
            return [
                0,
                1,
                1,
                2,
                1,
                3,
                2,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1

    def get_mendiane(self, level: int) -> int:
        try:
            return [
                0,
                0,
                0,
                0,
                3,
                0,
                2,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1

    def get_phiras(self, level: int) -> int:
        try:
            return [
                0,
                0,
                2,
                1,
                0,
                1,
                2,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1

    def get_thystame(self, level: int) -> int:
        try:
            return [
                0,
                0,
                0,
                0,
                0,
                0,
                1,
            ][level - 1]
        except (ValueError , IndexError):
            self.__errorRaised = True
            return -1
