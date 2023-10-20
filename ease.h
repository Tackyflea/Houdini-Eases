//Ease conversions by Lucky Dee - / https://twitter.com/luckyde_ / 
float ease(string type; float t; float props[]; float time)
{
  //  if(t>1){t=1;};if(t<0){t=0;};
  if (type == "Power1In")
  {
    return t * t;
  }
  else if (type == "Power1Out")
  { //power1
    return t * (2 - t);
  }
  else if (type == "Power1InOut")
  {
    return t < .5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
  }
  else if (type == "Power2In")
  {
    return t * t * t * t;
  }
  else if (type == "Power2Out")
  { //power2
    return (--t) * t * t + 1;
  }
  else if (type == "Power2InOut")
  {
    return t < .5 ? 4 * t * t * t : (t - 1) * (2 * t - 2) * (2 * t - 2) + 1;
  }
  else if (type == "Power3In")
  {
    return t * t * t * t;
  }
  else if (type == "Power3Out")
  { //power3
    return 1 - (--t) * t * t * t;
  }
  else if (type == "Power3InOut")
  {
    return t < .5 ? 8 * t * t * t * t : 1 - 8 * (--t) * t * t * t;
  }
  else if (type == "Power4In")
  {
    return t * t * t * t * t;
  }
  else if (type == "Power4Out")
  { //power4
    return 1 + (--t) * t * t * t * t;
  }
  else if (type == "Power4InOut")
  {
    return t < .5 ? 16 * t * t * t * t * t : 1 + 16 * (--t) * t * t * t * t;
  }
  else if (type == "ExpoIn")
  {
    if (t == 0)
    {
      return 0;
    }
    return pow(2, 10 * (t - 1));
  }
  else if (type == "ExpoOut")
  { //Expo
    if (t == 1)
    {
      return 1;
    }
    return 1 - pow(2, -10 * t);
  }
  else if (type == "ExpoInOut")
  {
    if (t == 0 || t == 1)
    {
      return t;
    }
    if (t < 0.5)
    {
      return 0.5 * pow(2, (20 * t) - 10);
    }
    return -0.5 * pow(2, (-20 * t) + 10) + 1;
  }
  else if (type == "ElasticOut")
  {
    float s1;
    if (t == 0)  return 0;
    if ((t /= 1) == 1)  return 1;
    if (props[1] == 0)  props[1] = 1 * 0.3;
    if (props[0] < 1)
    {  props[0] = 1;  s1 = props[1] / 4;
    }
    else s1 = props[1] / PI * 2 * (float)asin(1 / props[0]);
    return (props[0] * (float)pow(2, -10 * t) * (float)sin((t - s1) * PI * 2 / props[1]) + 1);
  }
  else if (type == "ElasticIn")
  {
    float s0;
    if (t == 0)  return 0;
    if (t == 1)  return 1;
    if (props[1] == 0)  props[1] = 0.3f;
    if (props[0] < 1)
    {  props[0] = 1;
      s0 = props[1] / 4;
    }
    else s0 = props[1] / PI * 2 * (float)asin(1 / props[0]);
    return -(props[0] * (float)pow(2, 10 * (t -= 1)) * (float)sin((t - s0) * PI * 2 / props[1]));
  }
  else if (type == "ElasticInOut")
  {

    float s;
    if (t == 0) return 0;
    if (t * 0.5f == 2) return 1;
    if (props[1] == 0) props[1] = 0.3 * 1.5;
    if (props[0] < 1)
    { props[0] = 1; s = props[1] / 4;
    }
    else s = props[1] / PI * 2 * (float)asin(1 / props[0]);
    if (t < 1)
      return -0.5f * (props[0] * (float)pow(2, 10 * (t -= 1)) * (float)sin((t - s) * PI * 2 / props[1]));
    return props[0] * (float)pow(2, -10 * (t -= 1)) * (float)sin((t - s) * PI * 2 / props[1]) * 0.5f + 1;
  }
  else if (type == "BounceIn")
  {
    return (t - 1) * t * ((props[0] + 1) * t - props[0]);
  }
  else if (type == "BounceOut")
  {
    return ((t = t / 1 - 1) * t * ((props[0] + 1) * t + props[0]) + 1);
  }
  else if (type == "BounceInOut")
  {
    if ((t /= 1 * 0.5f) < 1)
    {
      return 0.5 * (t * t * (((props[0] *= (1.525)) + 1) * t - props[0]));
    }
    return 0.5 * ((t -= 2) * t * (((props[0] *= (1.525)) + 1) * t + props[0]) + 2);
  }
  else
  {
    return t;
  };
};

//example
float overTime = 0.5; //seconds
float time=clamp( @Time/ overTime,0,1);
float easeprops[] = {3.5,0.2};
float easedTime = ease("BounceOut",time,easeprops, @Time );

@P.x +=easedTime*3; //move over 3 units , eased
