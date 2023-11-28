##
## EPITECH PROJECT, 2023
## server test
## File description:
## server test
##

import subprocess
import socket
import threading
import time
from queue import Queue

def connect_to_server(result_queue):
    host = 'localhost'
    port = 4242

    try:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((host, port))
        client_socket.close()
    except ConnectionRefusedError:
        print("\033[91mX ERROR Test_connection_serv: The connection was refused. Make sure the server is running.\033[0m")
        result_queue.put(1)
    except socket.error as e:
        print("\033[91mX ERROR Test_connection_serv: An error occurred during the connection:\033[0m", e)
        result_queue.put(1)
    else:
        result_queue.put(0)

def run_serv():
    chemin_fichier = '../zappy_server'

    try:
        subprocess.run([chemin_fichier, '-f', '100', '-c', '10', '-n', 'martin', '-y', '5', '-x', '5', '-p', '4242'], timeout=2)
    except:
        return 0

def Test_connection_serv():
    result_t2 = Queue()
    t1 = threading.Thread(target=run_serv)
    t2 = threading.Thread(target=connect_to_server, args=(result_t2,))
    t1.start()
    time.sleep(0.5)
    t2.start()
    t2.join()
    thread_result = result_t2.get()
    if thread_result != 1:
        print("\033[92mV Success Test_connection_serv\033[0m")
    t1.join(1)
    return 0
