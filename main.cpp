#include <functional>

class Enemy {
public:
    using StateFunction = std::function<void(Enemy&)>;

    // 初期状態は接近
    Enemy() : currentState(&Enemy::Approach) {}

    // 状態遷移を実行する関数
    void Update() {
        (this->currentState)(*this);
    }

private:
    // 状態遷移用のメンバ関数ポインタ
    StateFunction currentState;

    // 接近状態
    void Approach() {
        printf("Enemy is approaching.\n");

        // 何らかの条件で射撃に遷移
        currentState = &Enemy::Shoot;
    }

    // 射撃状態
    void Shoot() {
        printf("Enemy is shooting.\n");

        // 何らかの条件で離脱に遷移
        currentState = &Enemy::Withdraw;
    }

    // 離脱状態
    void Withdraw() {
        printf("Enemy is withdrawing.\n");

        // 何らかの条件で再び接近に遷移（ループする例）
        currentState = &Enemy::Approach;
    }
};

int main() {
    Enemy enemy;

    // 何らかの条件で敵の状態が変化するまで状態遷移を実行
    for (int i = 0; i < 5; ++i) {
        enemy.Update();
    }

    return 0;
}