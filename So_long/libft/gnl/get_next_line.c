/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:43:41 by jcavadas          #+#    #+#             */
/*   Updated: 2024/09/25 14:43:14 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_from_fd(char **stash, int fd)
{
	size_t	bytes_read;
	char	*buffer;
	char	*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	bytes_read = 1;
	while (stash != NULL && *stash && !ft_strchr(*stash, '\n')
		&& bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(stash);
			break ;
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		ft_free(stash);
		*stash = temp;
	}
	ft_free(&buffer);
}

char	*ft_extract_line(char **stash)
{
	size_t	i;
	char	*line;
	char	*temp;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if (i == ft_strlen(*stash))
	{
		line = ft_substr(*stash, 0, i);
		ft_free(stash);
		return (line);
	}
	else
	{
		i++;
		line = ft_substr(*stash, 0, i);
		temp = ft_substr(*stash, i, ft_strlen(*stash) - i);
		ft_free(stash);
		*stash = temp;
	}
	if (!line)
		ft_free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		return (NULL);
	}
	if (!stash)
		stash = ft_strjoin("", "");
	ft_read_from_fd(&stash, fd);
	if (stash == NULL)
		return (NULL);
	if (!ft_strlen(stash))
	{
		ft_free(&stash);
		return (NULL);
	}
	return (ft_extract_line(&stash));
}
