FROM nginx
WORKDIR /home/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY main.c .
COPY run.sh .
RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev
ENTRYPOINT ["sh", "./run.sh"]