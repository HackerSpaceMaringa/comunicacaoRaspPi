import socket

def iniciaSocket(port):
    HOST = '127.0.0.1'
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    info = (HOST, port)
    sock.connect(info)
    return sock


    
def main():
    sock = iniciaSocket(6666)
    message1 = "kenzo"   
    sock.send(message1)
    sock.close()
    
main()
