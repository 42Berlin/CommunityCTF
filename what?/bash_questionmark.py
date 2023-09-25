from fastapi import Request, Response, APIRouter
import subprocess

server = APIRouter()

not_allowed = '()$[];/|<>{}\'"!\\~`&*'

@server.get('/{arg}')
def get_arg(req: Request, arg: str):
    if 'deepest_secret.txt' in arg.lower():
        return Response('You cannot have "deepest_secret.txt" in your path', 403)

    for i in not_allowed:
        if i in arg:
            return Response('Not authorized characters in the path. List of non-authorised caracters: ' + not_allowed, 403)
    ret = subprocess.run(f'cat {arg}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return Response(ret.stdout.decode("utf-8") + ret.stderr.decode("utf-8"), 200)

@server.get('/')
def get_root():
    ret = subprocess.run(f'ls *.txt', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return Response("GET / needs an argument, example /hello.\n"
                    "Files available in the directory\n\n" +
                    ret.stdout.decode("utf-8"))
