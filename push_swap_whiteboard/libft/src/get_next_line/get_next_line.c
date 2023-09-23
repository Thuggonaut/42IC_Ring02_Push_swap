#include "../../inc/get_next_line.h"
#include "../../inc/libft.h"

char	*process_line(char **stash)
{
	char	*line;
	char	*leftovers;
	int		len;

	len = 0;
	while ((*stash)[len] != '\n' && (*stash)[len] != '\0')
		len++;
	if ((*stash)[len] == '\n')
	{
		line = ft_substr(*stash, 0, len + 1);
		leftovers = ft_substr(*stash, len + 1, ft_strlen(*stash) - (len + 1));
		free(*stash);
		*stash = leftovers;
		return (line);
	}
	return (NULL);
}

char	*read_from_fd(int fd)
{
	char	*line_read;
	int		read_bytes;

	line_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line_read)
		return (NULL);
	read_bytes = read(fd, line_read, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(line_read);
		return (NULL);
	}
	line_read[read_bytes] = '\0';
	return (line_read);
}

char	*get_next_line_helper(char **stash, int fd)
{
	char		*tmp_stash;
	char		*line_read;
	char		*line;

	line = process_line(stash);
	if (line)
		return (line);
	line_read = read_from_fd(fd);
	if (!line_read)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		if (*line)
			return (line);
		free(line);
		return (NULL);
	}
	tmp_stash = ft_strjoin(*stash, line_read);
	free(*stash);
	*stash = tmp_stash;
	free(line_read);
	return (get_next_line_helper(stash, fd));
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	return (get_next_line_helper(&stash[fd], fd));
}
