FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y g++ cmake build-essential

COPY . /app
WORKDIR /app

RUN cmake -S . -B build
RUN cmake --build build

CMD ["./build/snake"]
