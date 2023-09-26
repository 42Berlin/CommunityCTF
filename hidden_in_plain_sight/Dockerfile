FROM python

RUN pip install fastapi uvicorn

WORKDIR /app

COPY content.html /app/content.html

COPY main.py /app/main.py

CMD [ "uvicorn", "main:app", "--host=0.0.0.0" ]