from fastapi import FastAPI, Response
from fastapi.responses import HTMLResponse

app = FastAPI()

@app.get('/', response_class = HTMLResponse)
def get_root():
    f = open('content.html', 'r')
    content = f.read()

    return HTMLResponse(content, 200)