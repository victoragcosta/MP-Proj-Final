// Módulo de transações - Cabeçalho.

/**
 * @file transaction.h
 * @brief Cabeçalho do módulo de transações.
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avaliacao.h"
#include "error_level.h"
#include "product.h"

typedef enum {
  Friend,
  FriendOfFriend,
  Other
}relationship;

typedef enum {
  Open,
  InProgress,
  Closed,
  Canceled
}transactionStatus;

typedef struct userSpecification {
  relationship proximity;
  double minimum_rating;
  double maximum_rating;
}

typedef struct transaction {
  unsigned int user1;
  unsigned int user2;
  product item;
  transactionStatus status;
}

typedef struct transactionList {
  transaction *items; /**< Items na lista. Vetor de tipo transaction. */
  int size; /**< Tamanho da lista. Não pode ser negativo. */
}transactionList;

errorLevel CreateTransaction(unsigned int, unsigned int, product*,
                             transactionStatus, transaction);

#endif  // TRANSACTION_H_