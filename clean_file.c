#include <stdlib.h>
#include "minishell.h"  // Assuming necessary includes and t_token enum

// Helper to skip over quoted segments
int fly_over_quotes(const char *s, int i) {
    char quote = s[i];
    i++;
    while (s[i] && s[i] != quote)
        i++;
    return i; // Returns index after closing quote or at null terminator
}

// Identify operators: <, >, >>, <<, |
static int is_op(const char *s) {
    return (*s == '<' || *s == '>' || *s == '|');
}

// Calculate length of current token (word)
int toklen(const char *s, int i) {
    int start = i;
    while (s[i] && !ft_isspace(s[i]) && !is_op(&s[i])) {
        if (s[i] == '\'' || s[i] == '\"')
            i = fly_over_quotes(s, i);
        i++;
    }
    return i - start;
}

// Determine token type based on string value
t_token get_token_type(const char *str) {
    if (ft_strcmp(str, "<<") == 0)
        return (HEREDOC);
    if (ft_strcmp(str, ">>") == 0)
        return (RED_APPEND);
    if (ft_strcmp(str, "<") == 0)
        return (RED_IN);
    if (ft_strcmp(str, ">") == 0)
        return (RED_OUT);
    if (ft_strcmp(str, "|") == 0)
        return (PIPE);
    return (WORD);
}

// Add new token to linked list
t_shell *add_token(t_shell **head, const char *start, int len) {
    t_shell *new = malloc(sizeof(t_shell));
    t_shell *tmp;
    
    if (!new)
        return NULL;
    new->value = ft_substr(start, 0, len);
    new->kind = get_token_type(new->value);
    new->next = NULL;
    new->previous = NULL;

    if (!*head) {
        *head = new;
    } else {
        tmp = *head;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->previous = tmp;
    }
    return new;
}

// Main tokenization function
t_shell *tokenize(const char *s) {
    t_shell *head = NULL;

    while (*s) {
        // Skip whitespace
        while (ft_isspace(*s))
            s++;
        if (!*s)
            break;

        // Handle operators (2-char then 1-char)
        if (ft_strncmp(s, ">>", 2) == 0) {
            add_token(&head, s, 2);
            s += 2;
        } else if (ft_strncmp(s, "<<", 2) == 0) {
            add_token(&head, s, 2);
            s += 2;
        } else if (*s == '>') {
            add_token(&head, s, 1);
            s++;
        } else if (*s == '<') {
            add_token(&head, s, 1);
            s++;
        } else if (*s == '|') {
            add_token(&head, s, 1);
            s++;
        } 
        // Handle words (including quoted strings)
        else {
            int len = toklen(s, 0);
            add_token(&head, s, len);
            s += len;
        }
    }
    return (head);
}