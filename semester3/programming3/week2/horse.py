class Horse(object):
    def __init__(self, ranking=0, value=0):
        self.ranking = ranking
        self.value = value

    def display(self):
        print("Ranking: {}, Value: {:.0f}".format(self.ranking, self.value))


def main():
    horses = {}

    value = 1000
    for rank in range(100, 0, -1):
        horse = Horse(rank, value)
        horses[horse.ranking] = horse
        value *= 1.10

    user_input = int(input("Provide a horse rank.\nIf you type -1, all horses will be displayed: "))
    if user_input == -1:
        for rank in range (1, 101):
            horses[rank].display()
    elif 1 <= user_input <= 100:
        horses[user_input].display()
    else:
        print("A horse with rank {} was not found!".format(user_input))

if __name__ == '__main__':
    main()
