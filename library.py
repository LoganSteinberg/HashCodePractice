maxDays = 4
class Library():
    def __init__(self, libId, books, scanDays, maxPerDay, numBooks):
        self.libId = libId;
        self.numBooks = numBooks;
        self.books = books;
        #List of tuples [id, score]
        self.books.sort(key=lambda x: x[1], reverse=True);
        self.scanDays = scanDays;
        self.maxPerDay = maxPerDay;
        self.score = 0;

    def scoreLib(self):
        curIndex = 0
        #Maxdays constant for our deadline day
        for i in range(maxDays - self.scanDays):
            maxIndex = min(curIndex+self.maxPerDay, self.numBooks-1)
            self.score += sum(score for _, score in self.books[curIndex, maxIndex])
            curIndex = maxIndex
            #End if we've used all our books early.
            if curIndex >= self.numBooks:
                return self.score;
        return self.score;

