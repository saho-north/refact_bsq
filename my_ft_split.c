/*

#include "libft.h"

static void	*free_failed_malloc(char **dest, size_t word_no)
{
        size_t  i;

        i = 0;
        while (i < word_no)
        {
                free(dest[i]);
                i++;
        }
        free(dest);
        dest = NULL;
        return (NULL);
}

static char	**splitter(const char *str, char delimiter, char **dest,
                size_t word_count)
{
        size_t  word_no;
        size_t  word_len;

        word_no = 0;
        while (*str && word_no < word_count)
        {
                if (*str != delimiter)
                {
                        word_len = 0;
                        while (str[word_len] && str[word_len] != delimiter)
                                word_len++;
                        dest[word_no] = (char *)ft_calloc(word_len + 1,
		sizeof(char));
                        if (!dest[word_no])
                                return (free_failed_malloc(dest, word_no));
                        dest[word_no] = ft_memcpy(dest[word_no], str,
		word_len);
                        str += word_len;
                        word_no++;
                }
                else
                        str++;
        }
        return (dest);
}

static size_t	count_words(const char *str, char delimiter)
{
        size_t  word_count;
        bool    is_word;

        word_count = 0;
        is_word = false;
        while (*str)
        {
                if (!is_word && *str != delimiter)
                {
                        is_word = true;
                        word_count++;
                }
                else if (is_word && *str == delimiter)
                        is_word = false;
                str++;
        }
        return (word_count);
}

char	**ft_split(char const *str, char delimiter)
{
        char    **dest;
        size_t  word_count;

        if (!str)
                return (NULL);
        word_count = count_words(str, delimiter);
        dest = (char **)ft_calloc(word_count + 1, sizeof(char *));
        if (!dest)
                return (NULL);
        if (*str == '\0' && delimiter != '\0')
                return (dest);
        dest = splitter(str, delimiter, dest, word_count);
        if (!dest)
                return (NULL);
        dest[word_count] = NULL;
        return (dest);
}
 ~/42cursus/refact_bsq/ [main*]
 */
