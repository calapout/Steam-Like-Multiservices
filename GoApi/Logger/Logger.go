package Logger

import "log"

var logger log.Logger

func Init() {
	logger = log.Logger{}
}

func LogDebug(msg string) {
	logger.
}
