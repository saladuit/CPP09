# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    options.mk                                      |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2023/05/24 15:07:13 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2023/05/24 15:07:13 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

#	Flags
ifdef	DEBUG
	CFLAGS					+=-g -DDEBUG=1
endif

ifdef	FSAN
	CFLAGS					+=-fsanitize=address,undefined,leak
endif

ifdef	COV
	CFLAGS					+=--coverage
endif

# **************************************************************************** #
