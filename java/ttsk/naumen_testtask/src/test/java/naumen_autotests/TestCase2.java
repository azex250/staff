package naumen_autotests;

/**
 * Created by az on 27.01.16.
 */

import static org.junit.Assert.assertThat;
import static org.hamcrest.CoreMatchers.equalTo;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class TestCase2 {
    private ContactPage page;

    @Before
    public void setUp() {
        page = new ContactPage();
    }

    @Test
    public void runCase() {
        page.getElementByRow(0).click();
        page.scrollListToBottom();
        page.createContactClick();
        assertThat(page.getContactAmount(), equalTo(page.getShownContactAmount()));
    }

    @After
    public void afterTests() {
        page.quit();
    }
}

