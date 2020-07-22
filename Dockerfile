FROM balenalib/imx8mm-var-dart-ubuntu

RUN apt-get update && apt-get install -y build-essential

WORKDIR usr/src/app

COPY test.c ./test.c
COPY script.sh ./script.sh

RUN g++ test.c -o test

CMD ["bash", "./script.sh"]
