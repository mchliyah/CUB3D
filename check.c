void    find_first_horizontal_intersection(t_data *data, t_ray *ray)
{
    if (ray->is_ray_facing_up)
    {
        ray->ry = floor(data->player.pos.y / TILESIZE)
            * TILE_SIZE - 0.0001;
        ray->rx = data->player.pos.x + (ray->ry - data->player.pos.y)
            / tan(ray->ray_angle);
        ray->y0 = -TILE_SIZE;
        ray->x0 = ray->y0 / tan(ray->ray_angle);
    }
    else
    {
        ray->ry = floor(data->player.pos.y / TILE_SIZE)
            * TILE_SIZE + TILE_SIZE;
        ray->rx = data->player.pos.x + (ray->ry - data->player.pos.y)
            / tan(ray->ray_angle);
        ray->y0 = TILE_SIZE;
        ray->x0 = ray->y0 / tan(ray->ray_angle);
    }
}

void    find_horizontal_wall(t_data *data, t_ray *ray)
{
    int    mx;
    int    my;

    mx = 0;
    my = 0;
    find_first_horizontal_intersection(data, ray);
    while (TRUE)
    {
        if (find_horizontal_wall_helper(mx, my, data, ray))
            break ;
        else
        {
            ray->rx += ray->x0;
            ray->ry += ray->y0;
        }
    }
}