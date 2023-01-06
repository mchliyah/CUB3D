
#include "../../includes/parse.h"

int	ft_check_file(char **argv, char *filename)
{
	int	lent;
	int	p;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (!filename || fd < 0)
		return (0);
	lent = ft_strlen(filename);
	p = lent - 1;
	while (p > 0)
	{
		if (filename[p] == '.' && p + 3 == lent - 1)
		{
			if (filename[p + 1] == 'c' && filename[p + 2] == 'u'
				&& filename[p + 3] == 'b')
				return (1);
			else
				return (0);
		}
		p--;
	}
	return (0);
}

int	check_xpm(char *filename)
{
	int	lent;
	int	p;

	lent = ft_strlen(filename);
	p = lent - 1;
	while (p > 0)
	{
		if (filename[p] == '.' && p + 3 == lent - 1)
		{
			if (filename[p + 1] == 'x' && filename[p + 2] == 'p'
				&& filename[p + 3] == 'm')
				return (1);
			else
				return (0);
		}
		p--;
	}
	return (0);
}
