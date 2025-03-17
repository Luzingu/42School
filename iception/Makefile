all:
	docker compose up -d 

clean:
	docker rm -f $$(docker ps -aq);
	docker rmi -f $$(docker images)
