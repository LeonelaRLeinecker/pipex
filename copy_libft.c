#include "pipex.h"  

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (void *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
	s = (void *)temp;
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;

	len = ft_strlen(s) + 1;
	if (!s)
		return (NULL);
	result = (char *)malloc(len * (sizeof(char)));
	if (!result)
		return (NULL);
	return (ft_strcpy(result, (char *)s));
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;

	if (count == 0 || size == 0)
		return (malloc(0));
	temp = (char *)malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, count * size);
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_s;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (len > size_s - start)
		len = size_s - start;
	if (start > size_s)
		return (ft_strdup(""));
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}



static int	ft_sep_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag != 0)
		{
			flag = 0;
			count++;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	ft_word_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**create_memory(int size)
{
	char	**result;

	if (size <= 0)
		return (NULL);
	result = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (result);
}

char	**free_split(char **result)
{
	int	i;

	if (!result)
		return (NULL);

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)

{
	int		start;
	int		f_copied;
	int		string_size;
	int		sep;
	char	**result;

	start = 0;
	f_copied = (-1);
	sep = ft_sep_count(s, c);
	result = create_memory(sep + 1);
	if (!result)
		return (free_split(result));
	while (++f_copied < sep)
	{
		while (s[start] == c)
			start++;
		string_size = ft_word_size(&s[start], c);
		result[f_copied] = ft_substr(s, (unsigned int)start, string_size);
		if (!result[f_copied])
			return (free_split(result));
		start += string_size;
	}
    result[f_copied] = NULL;
	return (result);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	while (len_dst + i < size - 1 && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1s2;
	char	*str;

	len_s1s2 = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(len_s1s2 + 1, sizeof(char));
	if (!str)
		return (free(str), NULL);
	ft_strlcpy(str, s1, len_s1s2 + 1);
	ft_strlcat(str, s2, len_s1s2 + 1);
	return (str);
}