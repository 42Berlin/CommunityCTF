FROM python

RUN pip install uvicorn
RUN pip install fastapi

WORKDIR /app

COPY bash_questionmark.py /app/
COPY files/* /app/

CMD ["uvicorn", "bash_questionmark:server", "--host=0.0.0.0"]