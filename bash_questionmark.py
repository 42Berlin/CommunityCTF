from fastapi import Request, Response, APIRouter
import subprocess

server = APIRouter()

not_allowed = '()$[];/|<>{}\'"!\\~`&'

@server.get('/{arg}')
def get_arg(req: Request, arg: str):
    if 'flag.txt' in arg.lower():
        return Response('You cannot have "flag.txt" in your path', 403)

    for i in not_allowed:
        if i in arg:
            return Response('Not authorized characters in the path. List of non-authorised caracters: ' + not_allowed, 403)
    ret = subprocess.run(f'cat {arg}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return Response(str(ret.stdout) + str(ret.stderr), 200)

@server.get('/')
def get_root():
    return Response('GET / needs an argument, example /hello')
