//
// Created by user on 09.06.2022.
//

#ifndef OOP_SCORE_H
#define OOP_SCORE_H

template <typename T>
class Score
{
private:
    T score;
public:
    Score() = default;
    T getScore() const { return score;}
    explicit Score(T score) : score{score} {}
    Score(const Score<T>& s) : score{s.score} {}
    Score<T>& operator+=(T s) {this->score += s; return *this;}
};

#endif //OOP_SCORE_H
