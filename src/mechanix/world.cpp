#include <mechanix/world.hpp>
#include <mechanix/polygon.hpp>
#include <mechanix/line.hpp>

#include <iostream>
#include <cmath>

namespace mx
{

World::World()
{
}

World::~World()
{
}

Body::Ptr World::createBody(const BodyDef &bodyDef, const Shape *shape)
{
    Body::Ptr ptr(new Body(bodyDef, shape));
    m_bodies.push_back(ptr);
    return ptr;
}


void World::update(float timeStep)
{
    for(BodyList::iterator it = m_bodies.begin(); it != m_bodies.end(); ++it){
        (*it)->acceleration(m_gravitation*timeStep);
        (*it)->update(timeStep);
    }


    for(BodyList::iterator it = m_bodies.begin(); it != m_bodies.end(); ++it){
        BodyList::iterator ith = it;
        ith++;
        for(BodyList::iterator it2 = ith; it2 != m_bodies.end(); ++it2){
            if((*it)->getShape()->collide((*it2)->getShape().get())){
                Polygon *p1 = static_cast<Polygon *>((*it)->getShape().get());
                Polygon *p2 = static_cast<Polygon *>((*it2)->getShape().get());

                bool b = true;
                Line cl;

                Vector2f point1 = p1->getTransformedPoint(p1->getNumberOfPoints()-1);
                Vector2f point2 = p2->getTransformedPoint(p2->getNumberOfPoints()-1);

                for(size_t i = 0; i < p1->getNumberOfPoints(); ++i){
                    Line line1(p1->getTransformedPoint(i), point1-p1->getTransformedPoint(i));
                    point1 = p1->getTransformedPoint(i);
                    for(size_t j = 0; j < p2->getNumberOfPoints(); ++j){
                        Line line2(p2->getTransformedPoint(j), point2-p2->getTransformedPoint(j));
                        point2 = p2->getTransformedPoint(j);

                        float t1 = line1.intersects(line2);
                        float t2 = line2.intersects(line1);

                        if(0.f < t1 and t1 < 1.f and 0.f < t2 and t2 < 1.f){
                            Vector2f vec = line1.getPoint() + t1 * line1.getDirectionVector();
                            if(b){
                                cl.setPoint(vec);
                                b = false;
                            } else {
                                cl.setDirectionVector(vec - cl.getPoint());
                            }
                        }
                    }
                }
                Vector2f n = cl.getDirectionVector().normal();
                //n.normalize();
                Vector2f p = cl.getPoint()+(cl.getDirectionVector()/2.f);
                Body::Ptr b1 = (*it);
                Body::Ptr b2 = (*it2);

                mx::Vector2f r1(p - b1->getShape()->getPosition());
                mx::Vector2f r2(p - b2->getShape()->getPosition());

                mx::Vector2f rap = r1.normal();
                mx::Vector2f rbp = r2.normal();

                float rapn = dot(rap, n);
                float rbpn = dot(rbp, n);

                mx::Vector2f vp1(b1->getVelocity()+b1->getAngularVelocity()*rap);
                mx::Vector2f vp2(b2->getVelocity()+b2->getAngularVelocity()*rbp);
                mx::Vector2f vab(vp2 - vp1);

                float M1 = b1->getBodyDef().getMass();
                float M2 = b2->getBodyDef().getMass();
                float I1 = b1->getBodyDef().getMomentOfInertia();
                float I2 = b2->getBodyDef().getMomentOfInertia();

                float j = -(1+(b1->getBodyDef().getElasticity()+b2->getBodyDef().getElasticity())/2.f) * dot(vab, n);
                j /= dot(n, n)*(1.f/M1+1.f/M2) + rapn*rapn/I1 + rbpn*rbpn/I2;

                std::cout << "v1: " << b1->getVelocity().length() << " w1: " << b1->getAngularVelocity() << " "
                          << "v2: " << b2->getVelocity().length() << " w2: " << b2->getAngularVelocity() << std::endl;
                std::cout << "Energie: " << (pow(b1->getVelocity().length(), 2) * M1 + pow(b2->getVelocity().length(), 2) * M2 +
                                             pow(b1->getAngularVelocity(), 2) * I1 + pow(b2->getAngularVelocity(), 2) * I2) * 0.5f << std::endl;

                if(j > 0.f){
                    b1->acceleration(-(j/M1) * n);
                    b2->acceleration( (j/M2) * n);

                    b1->angularAcceleration(-j/I1 * rapn);
                    b2->angularAcceleration( j/I2 * rbpn);
                }

                vp1 = b1->getVelocity()+b1->getAngularVelocity()*rap;
                vp2 = b2->getVelocity()+b2->getAngularVelocity()*rbp;
                vab = vp2 - vp1;

                std::cout << "v1: " << b1->getVelocity().length() << " w1: " << b1->getAngularVelocity() << " "
                          << "v2: " << b2->getVelocity().length() << " w2: " << b2->getAngularVelocity() << std::endl;
                std::cout << "Energie: " << (pow(b1->getVelocity().length(), 2) * M1 + pow(b2->getVelocity().length(), 2) * M2 +
                                             pow(b1->getAngularVelocity(), 2) * I1 + pow(b2->getAngularVelocity(), 2) * I2) * 0.5f << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void World::setGravitation(const mx::Vector2f &gravitation)
{
    m_gravitation = gravitation;
}

mx::Vector2f World::getGravitation(void)
{
    return m_gravitation;
}

} //namespace mx
