package Models

import "gorm.io/gorm"

type Game struct {
	Id          int `gorm:"primaryKey"`
	Name        string
	Description string
}

func (game Game) GetGames(db *gorm.DB) ([]Game, error) {
	var games []Game
	tx := db.Find(&games)

	if tx.Error != nil {
		return make([]Game, 0), tx.Error
	}

	return games, nil
}

func (game Game) GetGame(db *gorm.DB) (Game, error) {
	tx := db.Find(&game)
	if tx.Error != nil {
		return game, tx.Error
	}
	return game, nil
}
