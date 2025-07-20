package Controllers

import (
	"GoApi/DB"
	"GoApi/Models"
	"encoding/json"
	"fmt"
	"github.com/gorilla/mux"
	"net/http"
	"strconv"
)

func AddGameRoutes() {
	r := mux.NewRouter()
	r.StrictSlash(true)
	r.HandleFunc("/games", gamesHandler).Methods(http.MethodGet)
	r.HandleFunc("/games/{id:[0-9]+}", gameHandler).Methods(http.MethodGet)
	http.Handle("/", r)
}

func gamesHandler(res http.ResponseWriter, req *http.Request) {
	// CHECK METHOD
	GameModel := Models.Game{}
	games, err := GameModel.GetGames(DB.GetDB())
	if err != nil {
		res.WriteHeader(http.StatusInternalServerError)
		return
	}

	res.WriteHeader(http.StatusOK)
	data, err := json.Marshal(games)
	_, err = res.Write(data)
	if err != nil {
		return
	}
}

func gameHandler(res http.ResponseWriter, req *http.Request) {
	// CHECK METHOD
	if req.Method != http.MethodGet {
		res.WriteHeader(http.StatusNotFound)
		return
	}

	// CHECK WE HAVE A VALID ID
	vars := mux.Vars(req)
	idString := vars["id"]
	if idString == "" {
		res.WriteHeader(http.StatusBadRequest)
		return
	}

	// PARSE THE ID
	id, err := strconv.Atoi(idString)
	if err != nil {
		res.WriteHeader(http.StatusInternalServerError)
		return
	}

	// GET THE DATA
	GameModel := Models.Game{}
	GameModel.Id = id
	game, err := GameModel.GetGame(DB.GetDB())
	if err != nil {
		res.WriteHeader(http.StatusInternalServerError)
		fmt.Printf("error while fetching game with id %d", GameModel.Id)
		return
	}

	// RETURN THE DATA
	data, err := json.Marshal(game)

	res.WriteHeader(http.StatusOK)
	_, err = res.Write(data)
	if err != nil {
		return
	}
}
