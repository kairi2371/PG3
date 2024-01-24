#include <functional>

class Enemy {
public:
    using StateFunction = std::function<void(Enemy&)>;

    // ������Ԃ͐ڋ�
    Enemy() : currentState(&Enemy::Approach) {}

    // ��ԑJ�ڂ����s����֐�
    void Update() {
        (this->currentState)(*this);
    }

private:
    // ��ԑJ�ڗp�̃����o�֐��|�C���^
    StateFunction currentState;

    // �ڋߏ��
    void Approach() {
        printf("Enemy is approaching.\n");

        // ���炩�̏����Ŏˌ��ɑJ��
        currentState = &Enemy::Shoot;
    }

    // �ˌ����
    void Shoot() {
        printf("Enemy is shooting.\n");

        // ���炩�̏����ŗ��E�ɑJ��
        currentState = &Enemy::Withdraw;
    }

    // ���E���
    void Withdraw() {
        printf("Enemy is withdrawing.\n");

        // ���炩�̏����ōĂѐڋ߂ɑJ�ځi���[�v�����j
        currentState = &Enemy::Approach;
    }
};

int main() {
    Enemy enemy;

    // ���炩�̏����œG�̏�Ԃ��ω�����܂ŏ�ԑJ�ڂ����s
    for (int i = 0; i < 5; ++i) {
        enemy.Update();
    }

    return 0;
}