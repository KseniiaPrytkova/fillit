/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktabl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlasov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:50:02 by evlasov           #+#    #+#             */
/*   Updated: 2018/01/13 17:50:03 by evlasov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_checkconf(char *str)
{
	int		i;
	int		j;
	int		n[4];
	int		term;

	i = 0;
	j = 0;
	term = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			n[j++] = i;
		i++;
	}
	term = ((n[1] - n[0]) * 1000) + ((n[2] - n[0]) * 100) + (n[3] - n[0]);
	if (term == 1203 || term == 1205 || term == 1207 || term == 1206
		|| term == 1405 || term == 1506 || term == 1510 || term == 1607
		|| term == 1611 || term == 3405 || term == 4506 || term == 4509
		|| term == 4510 || term == 5607 || term == 5610 || term == 5611
		|| term == 5910 || term == 6011 || term == 6015)
		return (1);
	return (0);
}

static int	ft_checkterm(char *str, int i)
{
	int		j;
	int		k;
	int		n;

	j = 1;
	k = 0;
	n = 0;
	while (j <= 20 && str[i])
	{
		if ((str[i] == '.' || str[i] == '#') && j % 5 != 0)
		{
			if (str[i] == '#')
				k++;
		}
		else if ((str[i] == '\n') && (j % 5 == 0))
			n++;
		else
			return (0);
		i++;
		j++;
	}
	if (k != 4 || n != 4 || (str[i] != '\n' && str[i] != '\0'))
		return (0);
	return (i);
}

static int	ft_checkform(char *str, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		if (ft_checkconf(str + (i * 21)) == 0)
			return (0);
		i++;
	}
	return (num);
}

int			ft_checktabl(char *str)
{
	int		i;
	int		num;

	i = 0;
	num = 1;
	while (str[i])
	{
		i = ft_checkterm(str, i);
		if (i == 0)
			return (0);
		if (str[i] == '\n')
		{
			i++;
			num++;
		}
		else if (str[i] == '\0' && num <= 26)
			return (ft_checkform(str, num));
	}
	return (0);
}
