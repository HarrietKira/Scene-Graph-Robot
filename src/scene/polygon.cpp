#include "polygon.h"
#include <glm/gtx/matrix_transform_2d.hpp>

Polygon2D::Polygon2D(OpenGLContext* context)
         : Drawable(context), m_vertPos(), m_vertIdx(), m_numVertices(0)
{}

Polygon2D::Polygon2D(OpenGLContext* context, int numSides)
         : Drawable(context), m_vertPos(), m_vertIdx(), m_numVertices(numSides)
{
    // Vertex positions
    glm::vec3 p(0.5f, 0.f, 1.f);
    float deg = glm::radians(360.f / numSides);
    for (int i = 0; i < numSides; i++)
    {
        glm::mat3 M = glm::rotate(glm::mat3(), i * deg);
        m_vertPos.push_back(M * p);
    }
    // Indices for triangulation
    int n = numSides - 2;
    for (int i = 0; i < n; i++)
    {
        m_vertIdx.push_back(0);
        m_vertIdx.push_back(i+1);
        m_vertIdx.push_back(i+2);
    }
}

Polygon2D::Polygon2D(OpenGLContext* context, const std::vector<glm::vec3>& positions)
         : Drawable(context), m_vertPos(positions), m_vertIdx(), m_numVertices(positions.size())
{
    int n = m_numVertices - 2;
    for (int i = 0; i < n; i++)
    {
        m_vertIdx.push_back(0);
        m_vertIdx.push_back(i+1);
        m_vertIdx.push_back(i+2);
    }
}

Polygon2D::Polygon2D(OpenGLContext* context, const std::vector<glm::vec3>& positions, bool convex)
         : Drawable(context), m_vertPos(positions), m_vertIdx(), m_numVertices(positions.size()), convex(convex)
{
    // check borader
    float x_min = positions[0][0];
    float x_max = positions[0][0];
    float y_min = positions[0][1];
    float y_max = positions[0][1];
    float z_min = positions[0][2];
    float z_max = positions[0][2];
    for(int i = 0; i < m_numVertices; i++)
    {
        if(positions[i][0] > x_max) x_max = positions[i][0];
        if(positions[i][0] < x_min) x_min = positions[i][0];
        if(positions[i][1] > y_max) y_max = positions[i][1];
        if(positions[i][1] < y_min) y_min = positions[i][1];
        if(positions[i][2] > z_max) z_max = positions[i][2];
        if(positions[i][2] < z_min) z_min = positions[i][2];
    }
    if (convex)
    {
        std::vector<glm::vec3> new_positions;
        new_positions.push_back(glm::vec3(x_min, y_max, z_min));
        new_positions.push_back(glm::vec3(x_max, y_max, z_min));
        new_positions.push_back(glm::vec3(x_max, y_min, z_min));
        new_positions.push_back(glm::vec3(x_min, y_min, z_min));
        this->m_vertPos = new_positions;
        this->m_numVertices = 4;
        int n = m_numVertices - 2;
        for (int i = 0; i < n; i++)
        {
            m_vertIdx.push_back(0);
            m_vertIdx.push_back(i+1);
            m_vertIdx.push_back(i+2);
        }
    }
    // if concave
    else
    {
        this->m_numVertices += 2;

    }
}

void Polygon2D::create()
{
    // Track our index count in a member variable
    // to be read by ShaderProgram::draw().
    m_count = m_vertIdx.size();
    m_numVertices = m_vertPos.size();

    // Create a VBO on our GPU and store its handle in bufIdx
    generateIdx();
    // Tell OpenGL that we want to perform subsequent operations on the VBO referred to by bufIdx
    // and that it will be treated as an element array buffer (since it will contain triangle indices)
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufIdx);
    // Pass the data stored in cyl_idx into the bound buffer, reading a number of bytes equal to
    // the number of indices multiplied by the size of a GLuint. This data is sent to the GPU to be read by shader programs.
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count * sizeof(GLuint), m_vertIdx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, m_bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_numVertices * sizeof(glm::vec3), m_vertPos.data(), GL_STATIC_DRAW);

    // Free up memory now that we no longer need the vertex info to be stored on the CPU
    m_vertIdx.clear();
    m_vertPos.clear();
}

void Polygon2D::setColor(glm::vec3 c)
{
    if (!bindCol())
    {
        generateCol();
    }
    std::vector<glm::vec3> colors(m_numVertices);
    std::fill(colors.begin(), colors.end(), c);
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, m_bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, m_numVertices * sizeof(glm::vec3), colors.data(), GL_STATIC_DRAW);
}
