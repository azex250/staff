package naumen_autotests;

/**
 * Created by az on 27.01.16.
 */

import static org.junit.Assert.assertThat;
import static org.hamcrest.CoreMatchers.equalTo;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TestCase3 {

    private ContactPage page;

    @Before
    public void setUp() {
        page = new ContactPage();
    }

    @Test
    public void runCase() {
        String new_name = "Test123";

        page.getElementByRow(0).click();
        page.createContactClick();
        page.getElementByRow(0).click();
        page.setInputName(new_name);
        page.updateContactClick();
        assertThat(page.getElementNameByRow(0), equalTo(new_name));
    }

    @After
    public void afterTests() {
        page.quit();
    }
}

