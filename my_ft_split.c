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
コードを読むと、文字列を指定した文字セットで分割する関数 `ft_split` を実装しているようですね。以下の点をリファクタリングする方向性として提案します：

1. **グローバル変数の除去**:
   - `g_word_index`, `g_start`, `g_end`,
	`g_state` のようなグローバル変数はコードの可読性や再利用性を低下させます。これらの変数を関数のローカル変数または引数として扱う方が望ましいです。

2. **状態管理の改善**:
  
	- `g_state` のような状態管理を、より読みやすく明確にすることができるでしょう。既に`t_word_state` enum を使用しているので、このenumを利用して状態管理を行うと良いでしょう。

3. **関数の分割**:
  
	- `ft_split` 内部での単語の取得と結果配列への追加を行う部分は、別の小さな関数として分割できるでしょう。これにより、関数の役割を細分化し、各関数が一つのタスクのみを担当するようにすることができます。

4. **エラーハンドリングの強化**:
   - `malloc` が失敗した場合の処理を追加することで、エラーハンドリングを強化できます。

5. **冗長な部分の最適化**:
  
	- 例えば、`ft_update_in_word` と `ft_add_last_word` 関数の中で、文字列をコピーする処理が似ている部分があります。これを一つの関数としてまとめることができるでしょう。

6. **変数名の改善**:
   - 一部の変数名がその用途や意味を正確に表していない場合があります。適切な名前を付けることで、コードの読み手が理解しやすくなります。

これらの方向性を元に、リファクタリングを行っていくことで、コードの可読性や再利用性、保守性を向上させることができるでしょう。
 ~/42cursus/refact_bsq/ [main*]
 */
