import emoji

def cool_emoji_pattern():
    for i in range(1, 6):
        for j in range(1, i + 1):
            print(emoji.emojize(":star:", use_aliases=True), end=" ")
        print()

    print(emoji.emojize(":thumbsup:", use_aliases=True) * 4)

    for i in range(4, 0, -1):
        for j in range(1, i + 1):
            print(emoji.emojize(":star:", use_aliases=True), end=" ")
        print()

if __name__ == "__main__":
    cool_emoji_pattern()
