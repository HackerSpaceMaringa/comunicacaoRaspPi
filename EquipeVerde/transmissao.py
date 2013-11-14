#! /usr/bin/python

import socket
from sys import argv
from threading import Thread

def iniciaSocket(port):
    HOST = ''
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    info = (HOST, port)
    sock.bind(info)
    sock.listen(1)
    return sock

def iniciaSocketEnviar():
    HOST = argv[1]
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    port = int(argv[2])
    info = (HOST, port)
    sock.connect(info)
    return sock

def sendInfo(msg):
    sockEnvio = iniciaSocketEnviar()
    sockEnvio.send(msg)
    sockEnvio.close()

def main():
    sock = iniciaSocket(6666)
    while True:
        (sockCliente, endereco) = sock.accept()
        while True:
            msg = sockCliente.recv(10)
            if not msg: break
            else:
                t = Thread(None, sendInfo, None, (msg,), {})
                t.start()
        sockCliente.close()



main()
