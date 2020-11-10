#include "stub_connectable.h"

stub_connectable::stub_connectable() {
    this->connexion_status = 0;
}

uint8_t stub_connectable::connected() {
    return this->connexion_status;
}

void stub_connectable::set_connexion(uint8_t connexion_status) {
    this->connexion_status = connexion_status;
}

int stub_connectable::connect(const char *host, uint16_t port) {
    return this->connexion_status;
}

void stub_connectable::stop() {
}

stub_connectable::~stub_connectable() {
}
