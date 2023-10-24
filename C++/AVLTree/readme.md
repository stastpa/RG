
I have traveled almost the whole world and I can say with a clear conscience that there is no nation that enjoys Christmas as much as these Kdovíci. When I had the opportunity to meet with the Kdovíci, I realized that it is not just a vision of gifts, fun in snowdrifts, and time spent with family and friends. What the Kdovíci feel for Christmas comes from the depths of their hearts and I would not hesitate to call it an almost animistic longing or an instinctive need for happy and undisturbed Christmas.

At least for the majority of them. Just like in any other group, there are exceptions among the Kdovíci. And I don't mean Grinches right now. I mean someone even worse. What could be worse than someone who, out of their own fear and sense of injustice, wants to steal Christmas from this nation, you ask? Well, it's the one who exploits these lowest human instincts, reinforces fear and uncertainty, and offers simple solutions to everything. And all this with the sole aim - to profit as much as possible. Yes, you guessed it right, dear readers. It is none other than the esteemed Mr. Mayor!

In such a naive nation as the Kdovíci, it is not surprising that the mayor has been ruling for several electoral periods in a row. Each time with a gain of more than 99% of the votes. Those of us who have been in the world for some time are also not surprised that in reality, taking care of the village is merely a side interest for the mayor. The mayor, in fact, owns the largest (and only, to be honest) toy store in Kdovík. A colossal conflict of interest, one might say! But it leaves the locals indifferent.

According to the proverb "appetite comes with eating," even the mayor doesn't have enough. Therefore, last year he launched an initiative called the Bestsellers. This involved the massive digitization of all purchases and the analysis of product sales. Based on the tremendous success that increased the mayor's profits tenfold, he plans to continue and take it to an even higher level this year. Ladies and gentlemen, welcome the Bestsellers II, an even more hideous scheme aimed at thoroughly emptying the wallets of the Kdovíci. Some say that this scheme will not only take away savings but may also steal a small piece of soul from each Kdovík.

And where do you fit into all this? After all, you are the good ones, you wouldn't dirty your hands with such despicableness. But the truth is that no one other than the city administration and the mayor's toy store will give you the contract. Moreover, you proved yourself last year. Therefore, this year, the implementation of the Bestsellers will be on you.

## Program Interface

Your task is to implement the template of the class `Bestsellers` parameterized by the type `Product`, which serves as the identifier of individual products. It is promised that the type `Product` has a copy constructor (and assignment operator), destructor, comparison operators, and `std::hash` implemented for it. The class `Bestsellers` must implement the following public methods:

- `size_t products() const` returning the number of recorded types of goods (i.e., **not** the number of items sold),

- `void sell(const Product& p, size_t amount)`, which records the sale of `amount` pieces of product `p`,

- `size_t rank(const Product& p) const`, which returns the ranking of the best-selling product, numbered from 1 (if multiple types of products have sold equally, you can rank them arbitrarily),

- `const Product& product(size_t rank) const` an inverse function to `rank` (so if no exception occurs, it always holds that `product(rank(p)) == p` and `rank(product(r)) == r`),

- `size_t sold(size_t r) const` the number of units sold of the product ranked `r` as the best-selling,

- `size_t sold(size_t from, size_t to) const` a version similar to the one-parameter version, but it returns the sum of units sold over the interval from `from` to `to` (inclusive of both endpoints; that is, `sold(r, r) == sold(r)` and `sold(1, products())` is the total number of units sold over all types of goods; the input `to < from` is considered invalid).

- **Bonus:** `size_t first_same(size_t r) const` and `size_t last_same(size_t r) const` return the smallest (or largest) rank `r'` for which `sold(r') == sold(r)`. These methods are only used in the bonus test. If you're not solving the bonus, keep the default implementation, which always returns 0.

If the arguments of the call are invalid (i.e., rank out of bounds or an unknown product in the `rank` method), throw the exception `std::out_of_range`.

## Grading Criteria

- To earn 1 point, it is necessary to functionally implement the interface described above, but the implementation does not need to be too efficient.

- For 3.5 points, the implementation must be efficient if the numbers of units sold are random, but the complexity of the `sold(from, to)` method may depend on `to - from`.

- For 7 points, the implementation must be efficient, but the complexity of the `sold(from, to)` method can still depend on `to - from`.

- For 10 points, the implementation must be efficient even for a large `to - from` in the `sold(from, to)` method.

- **Bonus:** To earn 12 points, it is necessary to correctly and efficiently implement the `first_same` and `last_same` methods.

## Notes

- Consider what is necessary to implement for passing each test.

- Solve the tests step by step. Do not try to achieve everything, including the bonus, in the first submission.

- When improving the implementation, you can use an older and slower version for testing it on large data.

- The type `Product` always has a default constructor, but those who have passed PA2 should not use it.

