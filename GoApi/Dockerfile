FROM golang:1.24.3 AS build

WORKDIR /app
COPY . .

RUN mkdir bin
RUN go mod download
RUN go build -o bin/GoApi .

FROM build AS release

WORKDIR /app
COPY --from=build /app/bin/GoApi .

ENTRYPOINT ["./GoApi"]