#include <iostream>

using namespace std;

class PaymentStrategy {
    public:
        virtual void handle() = 0;
};

class UPIPaymentStrategy : public PaymentStrategy {
    public:
        void handle() override {
            cout << "Paying via UPI" << endl;
        }
};

class CardStrategy : public PaymentStrategy {
    public:
        void handle() override {
            cout << "Paying via Card" << endl;
        }
};

class WalletStrategy : public PaymentStrategy {
    public:
        void handle() override {
            cout << "Paying via Wallet" << endl;
        }
};

class PaymentContext {
    PaymentStrategy *ps;

    public:
        PaymentContext() : ps(nullptr) {}

        void setStrategy(PaymentStrategy *p) {
            ps = p;
        }

        void pay(){
            ps->handle();
        }
};

int main() {

    PaymentContext pc;

    WalletStrategy ws;
    CardStrategy cs;
    UPIPaymentStrategy us;

    pc.setStrategy(&ws); // pay via wallet

    pc.pay();

    return 0;
}