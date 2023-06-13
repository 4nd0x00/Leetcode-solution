from collections import defaultdict
from typing import List
import heapq

# FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)


class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self._dict = defaultdict(list)
        self._food_rating = {}
        self._food_cuisine = {}
        for f, r, c in zip(foods, ratings, cuisines):
            heapq.heappush(self._dict[c], (-r, f))
            self._food_cuisine[f] = c
            self._food_rating[f] = r


    def changeRating(self, food: str, new_rating: int) -> None:
        cuisine = self._food_cuisine[food]
        self._food_rating[food] = new_rating
        heapq.heappush(self._dict[cuisine], (-new_rating, food))


    def highestRated(self, cuisine: str) -> str:
        curr = self._dict[cuisine]
        while curr:
            rating, food = curr[0]
            rating = -rating
            if rating == self._food_rating[food]:
                return food
            heapq.heappop(curr)
        return ''
