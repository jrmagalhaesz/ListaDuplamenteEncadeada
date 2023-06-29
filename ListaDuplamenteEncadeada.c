#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserido %d no início da lista.\n", data);
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Inserido %d no final da lista.\n", data);
}

void removeNode(Node** head, Node* node) {
    if (*head == NULL || node == NULL) {
        return;
    }
    if (*head == node) {
        *head = (*head)->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    free(node);
}

void displayFromBeginning(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos da lista a partir do início: ");
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void displayFromEnd(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
    } else {
        printf("Elementos da lista a partir do final: ");
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->prev;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("===== MENU =====\n");
        printf("1. Inserir valor no início\n");
        printf("2. Inserir valor no final\n");
        printf("3. Remover valor da lista\n");
        printf("4. Exibir lista a partir do início\n");
        printf("5. Exibir lista a partir do final\n");
        printf("6. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido no início: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &value);
                
                Node* current = head;
                while (current != NULL) {
                    if (current->data == value) {
                        removeNode(&head, current);
                        printf("Valor removido com sucesso.\n");
                        break;
                    }
                    current = current->next;
                }
                if (current == NULL) {
                    printf("O valor especificado não existe na lista.\n");
                }
                break;
            case 4:
                displayFromBeginning(head);
                break;
            case 5:
                displayFromEnd(head);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("\n");
    }

    return 0;
}
