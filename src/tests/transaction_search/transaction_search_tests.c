// Módulo de busca de transações - Testes.

/**

  @file transaction_search_tests.c
  @brief Arquivo que testa as funções relativas ao módulo de busca de transações
  do aplicativo.

*/

#include "transaction_search.h"

#include "gtest/gtest.h"

char name[75];
product new_product, new_product2;
transaction new_transaction, new_transaction2;
transactionList list, list2;
userRestriction restriction;

/* Inicialização das variáveis utilizadas nos testes.*/

TEST (Initialization, Variables) {

  CleanTransactionList(&list);

  strcpy(name, "Arroz");
  CreateProduct(name, Sale, 5, 100, &new_product);

  strcpy(name, "Feijão");
  CreateProduct(name, Sale, 7, 92, &new_product2);

  CreateTransaction(171, &new_product, &new_transaction);
  CreateTransaction(705, &new_product2, &new_transaction2);

  EXPECT_EQ(1, true);

}

TEST (AddTransaction, First) {

  ASSERT_EQ(list.size, 0);

  EXPECT_EQ(AddTransaction(&new_transaction, &list), Success);

  ASSERT_EQ(list.size, 1);
  EXPECT_EQ(list.items[0].user1, 171);
  EXPECT_EQ(list.items[0].user2, 171);
  EXPECT_EQ(list.items[0].status, Open);
  EXPECT_EQ(CompareProducts(&(list.items[0].item), &new_product), 0);

}

/*
  Teste da função AddTransaction para adicionar o segundo produto à uma lista de
  produtos.
 */

TEST (AddTransaction, Second) {

  ASSERT_EQ(list.size, 1);

  EXPECT_EQ(AddTransaction(&new_transaction2, &list), Success);

  ASSERT_EQ(list.size, 2);
  EXPECT_EQ(list.items[0].user1, 171);
  EXPECT_EQ(list.items[0].user2, 171);
  EXPECT_EQ(list.items[0].status, Open);
  EXPECT_EQ(CompareProducts(&(list.items[0].item), &new_product), 0);
  EXPECT_EQ(list.items[1].user1, 705);
  EXPECT_EQ(list.items[1].user2, 705);
  EXPECT_EQ(list.items[1].status, Open);
  EXPECT_EQ(CompareProducts(&(list.items[1].item), &new_product2), 0);

}

TEST (AddTransaction, Repeated_Transaction) {

  ASSERT_EQ(list.size, 2);

  EXPECT_EQ(AddTransaction(&new_transaction, &list), Failure);

  EXPECT_EQ(list.size, 2);

}

TEST (AddTransaction, Illegal_Users) {

  CleanTransactionList(&list);

  ASSERT_EQ(list.size, 0);

  new_transaction.user1 = 171;
  new_transaction.user2 = 171;
  new_transaction.status = InProgress;

  EXPECT_EQ(AddTransaction(&new_transaction, &list), Illegal_argument);

  ASSERT_EQ(list.size, 0);

}

TEST (AddTransaction, Illegal_Product) {

  ASSERT_EQ(list.size, 0);

  strcpy(new_product.name, "Sick dog");
  new_product.price = -5;
  new_product.popularity = 0;
  new_product.type = Sale;

  new_transaction.user1 = 171;
  new_transaction.user2 = 171;
  new_transaction.status = Open;
  CopyProduct(&(new_transaction.item), &new_product);

  EXPECT_EQ(AddTransaction(&new_transaction, &list), Illegal_argument);

  ASSERT_EQ(list.size, 0);

}

TEST (AddTransaction, Illegal_Transaction) {

  ASSERT_EQ(list.size, 0);

  strcpy(name, "Arroz");
  CreateProduct(name, Sale, 5, 100, &new_product);

  CreateTransaction(171, &new_product, &new_transaction);

  EXPECT_EQ(AddTransaction(NULL, &list), Illegal_argument);
  EXPECT_EQ(AddTransaction(&new_transaction, NULL), Illegal_argument);
  EXPECT_EQ(AddTransaction(NULL, NULL), Illegal_argument);

  ASSERT_EQ(list.size, 0);

}

/*
  Teste da função CleanTransactionList passando-se como argumento uma lista
  vazia.
 */

TEST (CleanTransactionList, New_List) {

  ASSERT_EQ((list2.items == NULL), true);

  EXPECT_EQ(CleanTransactionList(&list2), Success);

  ASSERT_EQ(list2.size, 0);
  ASSERT_EQ((list2.items == NULL), true);

}

/*
  Teste da função CleanTransactionList passando-se como argumento um ponteiro
  nulo.
 */

TEST (CleanTransactionList, Invalid_List) {

  EXPECT_EQ(CleanTransactionList(NULL), Illegal_argument);

}

TEST (CreateRestriction, Normal_Restriction) {

  EXPECT_EQ(CreateRestriction(Friend, 0, 5, &restriction), Success);
  EXPECT_EQ(restriction.proximity, Friend);
  EXPECT_EQ(restriction.minimum_rating, 0);
  EXPECT_EQ(restriction.maximum_rating, 5);

}

TEST (CreateRestriction, Invalid_Restriction) {

  EXPECT_EQ(CreateRestriction(Friend, 0, 5, NULL), Illegal_argument);

}

/*
  Finalização (desalocação de memória alocada dinamicamente) das variáveis
  utilizadas nos testes.
 */

TEST (Termination, Variables) {

  EXPECT_EQ(1, true);

}

int main(int argc, char **argv) {

::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}