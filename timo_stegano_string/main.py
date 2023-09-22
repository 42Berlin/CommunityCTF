from fastapi import FastAPI, Response

app = FastAPI()

@app.get('/')
def get_root():
    f = open('content.html', 'r')
    content = f.read()

    return Response(content, 200)