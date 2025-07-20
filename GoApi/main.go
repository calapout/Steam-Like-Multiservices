package main

import (
	"GoApi/Controllers"
	"GoApi/DB"
	"GoApi/Models"
	"net/http"
)

func main() {
	DB.OpenDB()
	db := DB.GetDB()

	err := db.AutoMigrate(&Models.Game{})
	if err != nil {
		panic("failed to migrate Game table")
	}

	Controllers.AddGameRoutes()

	_ = http.ListenAndServe(":8080", nil)
}
